// C++ program for coin change problem using dynamic programming
#include <bits/stdc++.h>
using namespace std;

int minCoins(vector<int> coins, int m, int V)
{
    //table[i] will be storing the minimum number of coinsrequired for i value. So table[V] will have result
    int table[V + 1];

    // Initialize all table values as Infinite
    for (int i = 1; i <= V; i++)
        table[i] = INT_MAX;

    // Base case (If given value V is 0)
    table[0] = 0;

    // Compute minimum coins required for all values from 1 to V
    for (int i = 1; i <= V; i++)
    {
        // Go through all coins smaller than i
        for (int j = 0; j < m; j++)
            if (coins[j] <= i)
            {
                int sub_res = table[i - coins[j]];
                cout << "i:" << i << " j:" << j << " sub_res" << sub_res << endl;
                if (sub_res + 1 < table[i])
                    table[i] = sub_res + 1;
                cout << "table[" << i << "]:" << table[i] <<" sub_res" << sub_res << endl;
            }
    }

    if (table[V] == INT_MAX)
        return -1;

    return table[V];
}

// Driver program to test above function
int main()
{
    int V;
    cin >> V;
    vector<int> coins{4, 1, 3};
    cout << minCoins(coins, coins.size(), V);
    return 0;
}