#include <bits/stdc++.h>
using namespace std;

class String
{
    char *name;
    int len;

public:
    String() = default;
    String(const char *str)
    {
        cout << "const call" << endl;
        len = strlen(str);
        name = new char[len];
        strcpy(name, str);
    }

    String(const String &a)
    {
        /* if (name)
            delete[] name; */
        cout << "copy const call" << endl;
        len = a.len;
        name = new char[len];
        strcpy(name, a.name);
    }

    String(String &&a) noexcept
    {
        /* if(name)
            delete[] name; */
        
        cout << "move const call" << endl;
        len = a.len;
        name = a.name;
       
        a.name = nullptr;
        a.len = 0;
    }

    String &operator=(const String &a)
    {
        if (name)
            delete[] name;
        cout << "copy assign call" << endl;
        len = a.len;
        name = new char[len];
        strcpy(name,a.name);
        return *this;
    }

    String& operator=(String &&a)
    {
        if (name)
            delete[] name;
        cout << "move assign call" << endl;
        len = a.len;
        name = new char[len];
        name = a.name;
        a.name = nullptr;
        a.len = 0;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &out, const String &f1);
    ~String()
    {
        cout << "dest call" << endl;
        delete[] name;
    }

    void setString(const char *s)
    {
        strcpy(name, s);
    }

    void show()
    {
        cout << name;
    }
};

std::ostream &operator<<(std::ostream &out, const String &f1)
{
    out << f1.name << endl;
    return out;
}

void aco(String g)
{
    cout<< "aco" <<endl;
}

int main()
{
    String s1 = "hello";
    String s3;
    s3=(move(String("hell")));   //without move copy const called
    /* String s4="k";
    s4=(move(s1));               //without move copy const called
    String s5 = "hi";//= std::move(s1);
    //s5 = move( s1);
    //s5.setString("hey");
    cout <<s5<<s4; */
    return 0;
}