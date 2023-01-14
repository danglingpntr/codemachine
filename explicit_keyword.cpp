#include <iostream>
using namespace std;

class Foo
{
private:
    int m_foo;

public:
    Foo(int foo) : m_foo(foo) {}       // if not use explicit then no error

    int GetFoo() { return m_foo; }
};

void DoBar(Foo foo)
{
    int i = foo.GetFoo();
}

int main()
{
    DoBar(42);
}