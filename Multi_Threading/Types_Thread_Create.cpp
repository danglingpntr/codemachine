#include<iostream>
#include<thread>
using namespace std;

//1. Function Pointer
// void fun(int x)
// {
//     while (x-- > 0)
//         cout<< x << endl;
// }
// int main()
// {
//     thread t1(fun,11);
//     thread t2(fun,10);
//     t1.join();
//     t2.join();
//     return 0;
// }

//----------------------------------------------------------------------------------------

//2. Lamda expression
// int main()
// {
//     //auto funLamda = [](int x){ while (x-- > 0) cout<< x << endl; };
    
//     thread t( [](int x) { while (x-- > 0) cout<< x << endl; }, 11);
//     t.join();
//     return 0;
// }

//----------------------------------------------------------------------------------------

//3. Functor (Function Object) 
// class Base
// {
// public:
//     void operator()(int x)
//     {
//         while (x-- > 0)
//             cout << x << endl;
//     }
// };

// int main()
// {
//     thread t(Base(),10);
//     t.join();
//     return 0;
// }

//----------------------------------------------------------------------------------------

//4.Non Static member function 
// class Base
// {
// public:
//     void run(int x)
//     {
//         while (x-- > 0)
//             cout << x << endl;
//     }
// };
// int main()
// {
//     Base b;
//     thread t(&Base::run,&b,10);
//     t.join();
//     return 0;
// }

//5.Static member function
class Base
{
public:
    static void run(int x)
    {
        while (x-- > 0)
            cout << x << endl;
    }
};
int main()
{
    thread t(&Base::run,10);
    t.join();
    return 0;
}