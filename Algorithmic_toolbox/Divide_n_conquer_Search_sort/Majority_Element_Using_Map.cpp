#include <bits/stdc++.h>
using namespace std;
 
void findMajority(vector<int> arr, int size)
{
    unordered_map<int, int> m;
    for(int i = 0; i < size; i++)
        m[arr[i]]++;
    int count = 0;
    for(auto i : m)
    {
        if(i.second > size / 2)
        {
            cout<<1;
            //cout << "Majority found :- " << i.first<<endl;
            return;
        }
    }
    cout<< 0;
}
 
// Driver code
int main()
{
     int a;
    cin >>a;
    vector<int> arr(a);
    for (int x = 0; x < a; x++)
    {
        cin >> arr[x];
    }
    int n = arr.size();
     
    // Function calling
    findMajority(arr, n);
    return 0;
}