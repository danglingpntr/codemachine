#include <iostream>
using namespace std;
int gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    long long a , b, lcm;
    cin>>a>>b;
    lcm=(a*b)/gcd(a, b);
    cout<<lcm<<endl;
    return 0;
}