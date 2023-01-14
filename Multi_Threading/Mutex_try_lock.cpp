#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

//if try_lock called again by same thread whivh owns the mutex, then it will show undefined condition.(Dead Lock condition)
//if want to lock same mutex by same thread more than one time then we need to use recursive_mutex.

int count;
mutex m;

void increase100000()
{
    for (int i = 0; i < 100000; i++)
    {
        if (m.try_lock())               //It's a non blocking call it just returns true or false on availablity of lock
        {
            // m.lock();
            count++;
            m.unlock();
        }
    }
}

int main()
{
    thread t1(increase100000);
    thread t2(increase100000);

    t1.join();
    t2.join();

    cout << count << endl;
    return 0;
}