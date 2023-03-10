/* Task-> The goal of this problem is to represent a given positive integer π as a sum of as many pairwise
distinct positive integers as possible. That is, to find the maximum π such that π can be written as
π1 + π2 + Β· Β· Β· + ππ where π1, . . . , ππ are positive integers and ππ ΜΈ= ππ for all 1 β€ π < π β€ π.

Input Format-> The input consists of a single integer π.
Constraints. 1 β€ π β€ 109.

Output Format-> In the first line, output the maximum number π such that π can be represented as a sum
of π pairwise distinct positive integers. In the second line, output π pairwise distinct */

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