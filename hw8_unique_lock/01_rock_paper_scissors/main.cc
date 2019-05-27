extern "C" {
#include <unistd.h>
}
#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <array>
#include <ctime>

using namespace std;

namespace game {

int num_a_wins;
int num_b_wins;

enum Shape {
  ROCK,
  PAPER,
  SCISSCORS,
  LAST
};
array<string, Shape::LAST> shape_str = {{
  "石頭",
  "布",
  "剪刀"
}};

void ShowStatistics() {
  cout << "累計獲勝: A: " << num_a_wins << "\tB: " << num_b_wins << endl << endl;
}

void ShowWinner(Shape a, Shape b) {
  cout << "A: " << shape_str[a] << "\tB:" << shape_str[b] << "\t... ";

  if (a == b) {
    cout << "Stalemate!" << endl;
    ShowStatistics();
    return;
  }

  switch (a) {
    case Shape::ROCK:
      cout << ((b == Shape::SCISSCORS) ? "A wins" : "B wins") << endl;
      if (b == Shape::SCISSCORS) {
        num_a_wins++;
      } else {
        num_b_wins++;
      }
      break;
    case Shape::PAPER:
      cout << ((b == Shape::ROCK) ? "A wins" : "B wins") << endl;
      if (b == Shape::ROCK) {
        num_a_wins++;
      } else {
        num_b_wins++;
      }
      break;
    case Shape::SCISSCORS:
      cout << ((b == Shape::PAPER) ? "A wins" : "B wins") << endl;
      if (b == Shape::PAPER) {
        num_a_wins++;
      } else {
        num_b_wins++;
      }
      break;
    default:
      break;
  }

  ShowStatistics();
}

int RandInt(int min, int max) {
  return (rand() % (max + 1 - min)) + min;
}

} // namespace game


int main(int argc, char* args[]) {
  srand(time(nullptr));

  const int kNumTimes = 5;
  game::num_a_wins = 0;
  game::num_b_wins = 0;

  // 出拳結果 are cached here
  game::Shape a;
  game::Shape b;

  mutex m1;
  mutex m2;

  unique_lock<mutex>* pm1 = nullptr;
  unique_lock<mutex>* pm2 = nullptr;

  thread t1 = thread([&]() {
    for (int i = 0; i < kNumTimes; i++) {
      unique_lock<mutex> lock1(m1, defer_lock);
      pm1 = &lock1;

      // 第一個人出拳
      a = static_cast<game::Shape>(game::RandInt(0, 2));
      sleep(1);
    }
  });

  thread t2 = thread([&]() {
    for (int i = 0; i < kNumTimes; i++) {
      unique_lock<mutex> lock2(m2, defer_lock);
      pm2 = &lock2;

      lock(*pm1, *pm2);

      // 第二個人出拳
      b = static_cast<game::Shape>(game::RandInt(0, 2));
      // 輸贏
      game::ShowWinner(a, b);
      sleep(1);
    }
  });

  t1.join();
  t2.join();
  return EXIT_SUCCESS;
}
