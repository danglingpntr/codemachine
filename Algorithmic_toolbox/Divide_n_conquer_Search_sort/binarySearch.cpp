#include <bits/stdc++.h>
using namespace std;

int binarySearch( vector<int> arr, int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        if (arr[m] == x)
            return m;

        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    
    return -1;
}

int binarySearchRecursv(vector<int> arr, int l, int r, int x)  //uses more memory for storing value in each recursive call.
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}


int main(void)
{
    int a,b;
    cin >>a;
    vector<int> arr(a);
    for (int x = 0; x < a; x++)
    {
        cin >> arr[x];
    }
    cin >>b;
    vector<int> find(b);
    for (int x = 0; x < b; x++)
    {
        cin >> find[x];
    }
    //int n = sizeof(arr) / sizeof(arr[0]);
    int n = arr.size();
    for (int x = 0; x < b; x++)
        cout<< binarySearch(arr, 0, n - 1, find[x]) << " ";
    //int result = binarySearch(arr, 0, n - 1, x); 
    //(result == -1) ? cout << "Element is not present in array" : cout << "Element is present at index " << result;
    return 0;
}