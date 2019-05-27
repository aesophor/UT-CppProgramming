extern "C" {
#include <unistd.h>
}
#include <iostream>
#include <string>
#include <thread>
#include <mutex>

using namespace std;

class Account {
 public:
  Account() : balance_() {}
  virtual ~Account() = default;

  void Deposit(int amount) {
    unique_lock<mutex> lock(m_);
    cout << "Depositing $" << amount << endl;
    balance_ += amount;
  }

  void Withdraw(int amount) {
    unique_lock<mutex> lock(m_);
    cout << "Withdrawing $" << amount << endl;
    balance_ -= amount;
  }

  friend ostream& operator<< (ostream& os, Account& account) {
    unique_lock<mutex> lock(account.m_);
    return os << "Balance: " << account.balance_ << endl;
  }

 private:
  mutex m_;
  int balance_;
};


int main(int argc, char* args[]) {
  Account account;

  thread t1 = thread([&]() {
    account.Deposit(500);
    cout << account << endl;
    sleep(2);
    account.Withdraw(200);
    cout << account << endl;
  });

  thread t2 = thread([&]() {
    account.Deposit(1000);
    cout << account << endl;
    sleep(2);
    account.Withdraw(300);
    cout << account << endl;

  });

  thread t3 = thread([&]() {
    account.Deposit(2000);
    cout << account << endl;
    sleep(2);
    account.Withdraw(500);
    cout << account << endl;
  });

  t1.join();
  t2.join();
  t3.join();

  return EXIT_SUCCESS;
}
