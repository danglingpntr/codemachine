#include <bits/stdc++.h>
using namespace std;

bool sortcol(const vector<int>& v1, const vector<int>& v2)
{
    return v1[1] < v2[1];
}

int findBreakTime(vector<vector<int>> &vect)
{
    sort(vect.begin(), vect.end(), sortcol);
    for (size_t i=0;i<vect.size();i++)
        for(size_t j =0;j<vect[i].size();j++)
            cout<<vect[i][j]<<" ";
    
}

int main()
{
    int n=0; cin>>n;
    vector<vector<int>> vec(n, vector<int> (2));
    for (size_t i=0;i<vec.size();i++)
        for(size_t j =0;j<vec[i].size();j++)
            cin>>vec[i][j];

    findBreakTime(vec);

    return 0;
}