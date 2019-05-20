#include <iostream>
#include <thread>

using namespace std;

int main(int argc, char* args[]) {
  thread t1([]() {
    int num = 0;
    for (int i = 0; i < 30; i++) {
      num += 2;
      cout << "+: " << num << endl;
    }
  });
  
  thread t2([]() {
    int num = 1;
    for (int i = 1; i <= 5; i++) {
      num *= i;
      cout << "!: " << num << endl;
    }
  });

  t1.join();
  t2.join();

  return EXIT_SUCCESS;
}
