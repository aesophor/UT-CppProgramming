extern "C" {
#include <unistd.h>
}
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

namespace {
mutex m;
} // namespace

int main(int argc, char* args[]) {
  int min = 0;

  cout << "幾分鍾後提醒你吃泡麵? ";
  cin >> min;

  thread t([=]() {
    unique_lock<mutex> lock(m);
    cout << min << "分鍾後提醒吃泡麵" << endl;
    sleep(min * 60);
    cout << "欸塞甲泡咪啊" << endl;
  });
  t.join();

  return EXIT_SUCCESS;
}
