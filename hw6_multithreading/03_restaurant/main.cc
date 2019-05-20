#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <ctime>

using namespace std;

namespace {
  mutex m;
  int numPreparedMeal = 0; // shared variable
} // namespace


int randBetween(int low, int hi) {
  return (rand() % (hi + 1 - low)) + low;
}

int getNumPreparedMeal() {
  ::m.lock();
  int result = ::numPreparedMeal;
  ::m.unlock();
  return result;
}

void cookMeal() {
  for (int i = 1; i <= 10; i++) {
    // 煮一盤菜 2秒
    this_thread::sleep_for(chrono::duration<int, std::milli>(2000));

    ::m.lock();
    ::numPreparedMeal++;
    cout << "煮好了第" << i << "盤" << endl;
    ::m.unlock();
  }
}

void deliverMeal() {
  for (int i = 1; i <= 10; i++) {
    while (getNumPreparedMeal() == 0) {
      ;
    }
    // 送一道菜 0.5秒
    this_thread::sleep_for(chrono::duration<int, std::milli>(500));

    ::m.lock();
    ::numPreparedMeal--;
    cout << "已經送了" << i << "盤" << endl;
    ::m.unlock();
  }
}


int main(int argc, char* args[]) {
  srand(time(nullptr));

  thread t1(&cookMeal);
  thread t2(&deliverMeal);

  t1.join();
  t2.join();

  return EXIT_SUCCESS;
}
