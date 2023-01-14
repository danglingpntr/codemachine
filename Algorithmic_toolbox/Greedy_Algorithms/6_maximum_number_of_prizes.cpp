/* Task-> The goal of this problem is to represent a given positive integer 𝑛 as a sum of as many pairwise
distinct positive integers as possible. That is, to find the maximum 𝑘 such that 𝑛 can be written as
𝑎1 + 𝑎2 + · · · + 𝑎𝑘 where 𝑎1, . . . , 𝑎𝑘 are positive integers and 𝑎𝑖 ̸= 𝑎𝑗 for all 1 ≤ 𝑖 < 𝑗 ≤ 𝑘.

Input Format-> The input consists of a single integer 𝑛.
Constraints. 1 ≤ 𝑛 ≤ 109.

Output Format-> In the first line, output the maximum number 𝑘 such that 𝑛 can be represented as a sum
of 𝑘 pairwise distinct positive integers. In the second line, output 𝑘 pairwise distinct */

#include <bits/stdc++.h>
using namespace std;
        
void maxPrize(int n)
{
    vector<int> prize;
    unsigned long long int winners = 1L;
    if (n == 2)
    {
        cout << n;
        return;
    }
    while (true)
    {
        if (n - winners <= winners)
        {
            prize.push_back(n);
            n = 0;
        }
        else
        {
            n -= winners;
            prize.push_back(winners);
            winners++;
        }
        if (n == 0)
        {
            break;
        }
    }
    cout << winners << endl; 
    for(int i=0; i<prize.size(); i++)
        cout<<prize[i]<<" ";
    cout<<endl;
    return;
}

int main()
{
    int x;
    cin>>x;
    maxPrize(x);
    return 0;
}