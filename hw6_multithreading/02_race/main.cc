#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <ctime>

using namespace std;

namespace {
  mutex m;
} // namespace

int randBetween(int low, int hi) {
  return (rand() % (hi + 1 - low)) + low;
}

void run(const string& name, int sec) {
  int length = 0;
  for (int i = 0; i < sec; i++) {
    this_thread::sleep_for(chrono::duration<int, std::milli>(1000));
    length += randBetween(1, 10);

    ::m.lock();
    cout << name << " 累計跑了 " << length << "m." << endl;
    ::m.unlock();
  }
}

int main(int argc, char* args[]) {
  srand(time(nullptr));

  thread t1(&run, "A", 10);
  thread t2(&run, "B", 10);

  t1.join();
  t2.join();

  return EXIT_SUCCESS;
}
