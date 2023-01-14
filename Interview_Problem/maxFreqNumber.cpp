#include <bits/stdc++.h>
using namespace std;

int mostFrequent(vector<int> arr, int n)
{
    // Insert all elements in hash.
    unordered_map<int, int> hash;
    for (int i = 0; i < n; i++)
        hash[arr[i]]++;
 
    // find the max frequency
    int max_count = -1, res = -1;
    for (auto i : hash) {
        if (max_count==i.second)
            return -1;
        else if (max_count < i.second) {
            res = i.first;
            max_count = i.second;
        }
    }
 
    return res;
}

int main()
{
    int n;
    cout << "Enter the number of items:"
         << "\n";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " items" << endl;
    for (int x = 0; x < n; x++)
    {
        cin >> arr[x];
    }
    cout << mostFrequent(arr,n);
    return 0;
}