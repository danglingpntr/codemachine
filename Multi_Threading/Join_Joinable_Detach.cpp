#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

void run(int x)
{
    while (x-- > 0)
        cout << "Running.." << endl;
    this_thread::sleep_for(chrono::seconds(3)); //It is not able to hold for detach, It only work for join
}

//JOIN
// int main()
// {
//     thread t(run,11);
//     cout<<"main"<<endl;
//     if(t.joinable())             //Safe to check whether thread is ready to joinable i.e, not joined before
//         t.join();                //It forces thread to complete, after completion (parent/main) thread will run
//     cout<<"main goin end"<<endl;
//     return 0;
// } 

//DETACH
int main()
{ 
    thread t(run, 11);
    cout << "main" << endl;
    if (t.joinable())
        t.detach();                  //It do not wait thread to complete,
    cout << "main goin end" << endl; //after thread will run before main thread ends(if its fast enough)
    this_thread::sleep_for(chrono::seconds(3));     // Use to see detach behaviour
    return 0;
}