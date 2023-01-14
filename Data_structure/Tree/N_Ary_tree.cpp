#include <bits/stdc++.h>                          
using namespace std; 

vector<vector<int>> vec;

void dfs(int val)
{
    cout << val << " ";
    for (const int node: vec[val])
        dfs(node);
}

int main()
{
    int nodes, edges, x , y;
    cin>>nodes>>edges; 
    vec.resize(nodes+1);
    while(edges--)
    {
        cin>> x >> y;
        vec[x].push_back(y);
    }
    dfs(1);   // (root_node)
    return 0;
}

// 7 6
// 1 2
// 1 3
// 2 4
// 2 5
// 2 6
// 3 7