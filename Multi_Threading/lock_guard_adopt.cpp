#include <mutex>
#include <thread>
#include <iostream>

class BankAccount 
{
 public:
    explicit BankAccount(int balance): balance(balance) {}
    int getBalance() { return balance; }
    friend void transfer(BankAccount* fromAcc, BankAccount* toAcc, int amount);
 private:
    int balance;
    std::mutex m;
};

void transfer(BankAccount* fromAcc, BankAccount* toAcc, int amount)                   //with friend
//void BankAccount::transfer(BankAccount* fromAcc, BankAccount* toAcc, int amount)    //with-out friend
{
    // first two mutexes are locked
    std::lock(fromAcc->m, toAcc->m);
    // two lock_guard instances are constructed, one for each mutex
    // std::adopt_lock parameter specifies that mutexes are already
    // locked, and they should just adopt the ownership  of the existing
    // lock on the mutex rather than attempt to lock the mutex in the
    // constructor.
    std::lock_guard<std::mutex> lock1(fromAcc->m, std::adopt_lock);          //unique also work same here
    std::lock_guard<std::mutex> lock2(toAcc->m, std::adopt_lock);

    fromAcc->balance -= amount;
    toAcc->balance += amount;
}

int main() 
{
    BankAccount person1(100);
    BankAccount person2(200);

    std::cout << "Balance person1: " << person1.getBalance() << std::endl;
    std::cout << "Balance person2: " << person2.getBalance() << std::endl;

    //with using friend trnsfer member fun
    std::thread t1(transfer, &person1, &person2, 50);
    std::thread t2(transfer, &person2, &person1, 20);

    //without using firend for transfer
    // std::thread t1(&BankAccount::transfer,&person1, &person1, &person2, 50);
    // std::thread t2(&BankAccount::transfer,&person2, &person2, &person1, 20);

    if (t1.joinable()) t1.join();
    if (t2.joinable()) t2.join();

    std::cout << "Balance person1 after transfer: " <<
        person1.getBalance() << std::endl;
    std::cout << "Balance person2 after transfer: " <<
        person2.getBalance() << std::endl;

    return 0;
}