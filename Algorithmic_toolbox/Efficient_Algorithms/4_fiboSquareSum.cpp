#include <iostream>
using namespace std;

int getFibonacciLastDigit(long n)
{
    if (n <= 1)
        return (int)n;

    int prev = 0;
    int curr = 1;
    for (long i = 2; i <= n; i++)
    {
        int next = (prev + curr) %10;
        prev = curr;
        curr = next;
    }
    return curr%10;
}

int getFibonacciSumSquares(long n)
{
    int verticalSide = getFibonacciLastDigit(n);
    int horizontalSide = getFibonacciLastDigit((n + 1));
    int sumSquares = verticalSide * horizontalSide;
    return sumSquares%10;
}

int main()
{
    long number;
    cin >> number;
    cout<<getFibonacciSumSquares(number);
    return 0;
}