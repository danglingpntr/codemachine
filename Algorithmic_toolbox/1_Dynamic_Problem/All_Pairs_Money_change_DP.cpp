// C++ program for find all pairs of coins for coin change problem using dynamic programming
#include <bits/stdc++.h>
using namespace std;

int count(int S[], int n, int V)
{
    //table[i] will be storing the number of solutions for value i. We need n+1 rows as the table is constructed
    //in bottom up manner using the base case (n = 0)
    int table[V + 1];
    memset(table, 0, sizeof(table));

    table[0] = 1;   // Base case (If given value is 0) Pick all coins one by one and update the table[] 
                    // values after the index greater than or equal to the value of the picked coin
    for (int i = 0; i < n; i++)
        for (int j = S[i]; j <= V; j++)
        {
            table[j] += table[j - S[i]];
            cout << "for j:" << j << " table:" << table[j] << " "<<endl;
        }
    for (int i=0;i<n;i++)
        cout<<table[i]<<endl;

    return table[n];
}

int main() 
{
    int arr[] = {4, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int V;
    cout<<"Enter VAl:";
    cin>>V;
    cout << count(arr, n, V);
    return 0;
}