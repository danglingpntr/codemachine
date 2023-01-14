#include <iostream>
using namespace std;

int main()
{
    unsigned long long n1 = 0, n2 = 1, n3, i, number;
    cin >> number;
    cout << n1 << " " << n2 << " ";
    for (i = 2; i < number; ++i) // loop starts from 2 because 0 and 1 are already printed
    {
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
        cout << n3 << " ";
    }
    return 0;
}