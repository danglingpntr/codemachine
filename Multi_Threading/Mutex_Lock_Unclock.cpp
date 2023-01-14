#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

int count;
mutex m;

void increase()
{
    for (int i = 0; i < 1000000; i++)
    {
        m.lock();                          //It blocks the another thread to access the variable
        count++;
        m.unlock();
    }
}

int main()
{
    thread t1(increase);
    thread t2(increase);

    t1.join();
    t2.join();

    cout << count << endl;
    return 0;
}