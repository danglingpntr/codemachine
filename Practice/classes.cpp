#include <bits/stdc++.h>
using namespace std;

int minMoves(vector<int> &arr, int n)
{
    int expectedItem = n;
    for (int i=n-1; i >= 0; i--)
    {
        if (arr[i] == expectedItem)
            expectedItem--;
    }
 
    return expectedItem;
}

int main()
{
    int n;
	cin >>n;
	vector<int> vect(n);
	for (int i=0;i<n;i++)
		cin>>vect[i];
    cout << minMoves(vect,n);
    return 0;
}