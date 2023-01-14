#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<unsigned long long> table;
    table.push_back(0L);
    table.push_back(1L);

    if (n == 0) {
        cout << n << endl;
    }
    else if (n == 1) {
        cout << n << endl;
    }
    else 
    {
        for (int i = 2; i <= n; i++) {
            cout<<" "<<pow(table[i - 1],2) <<" "<< pow(table[i - 2],2)<< endl;
            table.push_back( ((long) pow(table[i - 1],2)% 10 + (long)pow(table[i - 2],2)% 10 ));
            cout<<" "<<table[i]<<endl;
        }
    }

    cout << table[n];
    return 0;
}