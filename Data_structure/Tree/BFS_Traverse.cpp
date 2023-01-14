#include <bits/stdc++.h>                          
using namespace std; 

vector<vector<int>> vec;
vector<bool> visited;

void initialize()
{
    for (int i=0; i<visited.size(); i++)
        visited[i]=false;
}

void bfs(int s)
{
    queue<int> que;
    que.push(s);
    visited[s]=true;
    while (!que.empty())
    {
        int node = que.front();
        que.pop();
        cout << "Visistd :"<< node << " ";
        for (int i=0; i<vec[node].size(); i++)
        {
            if(!visited[vec[node][i]])
            {
                que.push(vec[node][i]);
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
    bfs(1);   // (vector,root_node)
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