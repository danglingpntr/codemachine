#include <iostream>
using std::cout;
using std::endl;

class EventHandler
{
    public:
        template<typename T>
        void addHandler(T* owner)
        {
            cout << "Handler added..." << endl;
            //Let's pretend an event just occured
            owner->Callback(owner,1);
        }
};

EventHandler* handler;

class MyClass
{
    public:
        MyClass();
        void Callback(MyClass* instance, int x);
    private:
        int private_x;
};

MyClass::MyClass()
{
    private_x = 5;
    handler->addHandler(this);
}
void MyClass::Callback(MyClass* instance, int x)
{
    cout << x + instance->private_x << endl;
}

class YourClass
{
    public:
        YourClass();
        void Callback(YourClass* instance, int x);
    private:
        int private_x;
};

YourClass::YourClass()
{
    private_x = 9;
    handler->addHandler(this);
}
void YourClass::Callback(YourClass* instance, int x)
{
    cout << x + instance->private_x << endl;
}

int main(int argc, char** argv)
{
    handler = new EventHandler();
    MyClass* myClass = new MyClass();
    YourClass* yourClass = new YourClass();
}