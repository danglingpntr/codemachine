#include <bits/stdc++.h>                          
using namespace std; 

vector<vector<int>> vec;
vector<bool> visited;

void initialize()
{
    for (int i=0; i<visited.size(); i++)
        visited[i]=false;
}

void dfs_r(int s) 
{
    visited[s]=true;
    cout<<"Traverse"<< s << " "<<endl;
    for (int i=0; i<vec[s].size(); i++)
    {
        cout<< visited[vec[s][i]] << " "<<endl;
        if (visited[vec[s][i]]== false)
            dfs_r(vec[s][i]);
    }
}

void dfs(int s)
{
    stack<int> stk;
    stk.push(s);
    visited[s]=true;
    while (!stk.empty())
    {
        int node = stk.top();
        stk.pop();
        cout << node << " ";
        for (int i=0; i<vec[node].size(); i++)
        {
            if(!visited[vec[node][i]])
            {
                stk.push(vec[node][i]);
                visited[vec[node][i]]=true;
            }
        }
    }
}

int main()
{
    int nodes, edges, x , y;
    cin>>nodes>>edges;
    vec.resize(nodes+1);
    visited.resize(nodes+1);
    for (int i=0; i<edges; i++)
    {
        cin>> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    initialize();
    dfs_r(1);
    //dfs(1);   // (root_node)
    
    return 0;
}

// 6 7
// 1 2
// 1 4
// 4 5
// 2 4
// 2 3
// 3 6
// 4 6

/*       1
       /   \
     4 -----2
   /  \       \
 5     6-------3 */

