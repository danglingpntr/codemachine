#include <iostream>
int foo()
{
    std::cout<<"hi foo";
    return 5;
}
 
int goo(int a)
{
    std::cout<<"hi"<<a;
    return 6;
}
 
int main()
{
    int (*fcnPtr)(){ &foo }; // fcnPtr points to function foo
    //fcnPtr = &goo; // fcnPtr now points to function goo
    (*fcnPtr);
 
    return 0;
}