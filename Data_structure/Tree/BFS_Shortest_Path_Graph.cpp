
#include <bits/stdc++.h>
using namespace std;
 
void add_edge(vector<int> adj[], int src, int dest)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

bool BFS(vector<int> adj[], int src, int dest, int v, int pred[], int dist[])
{
    list<int> queue;
    bool visited[v];

    for (int i = 0; i < v; i++) 
    {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }
 
    // now source is first to be visited and
    // distance from source to itself should be 0
    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);
 
    // standard BFS algorithm
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        for (int i = 0; i < adj[u].size(); i++) 
        {
            if (visited[adj[u][i]] == false) 
            {
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                pred[adj[u][i]] = u;
                queue.push_back(adj[u][i]);
 
                // We stop BFS when we find
                // destination.
                if (adj[u][i] == dest)
                    return true;
            }
        }
    }
 
    return false;
}

void printShortestDistance(vector<int> adj[], int s, int dest, int v)
{
    // predecessor[i] array stores predecessor of i and distance array stores distance of i from s
    int pred[v], dist[v];
 
    if (BFS(adj, s, dest, v, pred, dist) == false) 
    {
        cout << "Given source and destination are not connected";
        return;
    }
 
    // vector path stores the shortest path
    vector<int> path;
    int crawl = dest;
    path.push_back(crawl);
    while (pred[crawl] != -1) 
    {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }
 
    // distance from source is in distance array
    cout << "Shortest path length is : " << dist[dest];
 
    // printing path from source to destination
    cout << "\nPath is:";
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
}
 
// Driver program to test above functions
int main()
{
    // no. of vertices
    int v = 8;
    vector<int> adj[v];
    add_edge(adj, 0, 1);
    add_edge(adj, 0, 3);
    add_edge(adj, 1, 2);
    add_edge(adj, 3, 4);
    add_edge(adj, 3, 7);
    add_edge(adj, 4, 5);
    add_edge(adj, 4, 6);
    add_edge(adj, 4, 7);
    add_edge(adj, 5, 6);
    add_edge(adj, 6, 7);
    int source = 4, dest = 2;
    printShortestDistance(adj, source, dest, v);
    return 0;
}