//std::lock_guard<mutex> lock(m1)

// Notes:
// 1. Its a very light weight wrapper for owing mutex on scoped basis.
// 2. It acquires mutex lock the moment you create the boject of lock guard.
// 3. It automatically removes the lock while goes out of scope.
// 4. You can not explicitily unlock the lock guard
// 5. cannnot copy this lock  

#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

std::mutex m1;
int buffer = 0;

void task(const char* threadNumber, int loopFor)
{
    //m1.lock();                                  //Must be lock before using adopt_lock, unique also work same here
    lock_guard<mutex> lock(m1,adopt_lock);        //It can only use adopt_lock
    for (int i=0;i<loopFor;i++)
    {
        buffer++;
        cout<< threadNumber << buffer<< endl;
    }
}

int main()
{
    thread t1(task,"T0 ",10);
    thread t2(task,"T1 ",10);

    t1.join();
    t2.join();

    return 0;
}