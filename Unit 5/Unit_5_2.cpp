#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS Traversal
vector<int> BFS(int start, int n, vector<int> adj[]) {
    vector<int> vis(n + 1, 0);
    queue<int> q;
    vector<int> bfs;

    vis[start] = 1;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (int nbr : adj[node]) {
            if (!vis[nbr]) {
                vis[nbr] = 1;
                q.push(nbr);
            }
        }
    }

    return bfs;
}

// DFS Utility
void dfsUtil(int node, vector<int> adj[], vector<int>& vis, vector<int>& dfs) {
    vis[node] = 1;
    dfs.push_back(node);

    for (int nbr : adj[node]) {
        if (!vis[nbr]) {
            dfsUtil(nbr, adj, vis, dfs);
        } 
    }
}

// DFS Traversal
vector<int> DFS(int start, int n, vector<int> adj[]) {
    vector<int> vis(n + 1, 0);
    vector<int> dfs;

    dfsUtil(start, adj, vis, dfs);
    return dfs;
}

int main() {
    int n, e;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<int> adj[n + 1];

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // for undirected graph
    }

    int start;
    cout << "Enter start node for BFS/DFS: ";
    cin >> start;

    // BFS
    vector<int> bfs = BFS(start, n, adj);
    cout << "BFS Traversal: ";
    for (int x : bfs) cout << x << " ";
    cout << endl;

    // DFS
    vector<int> dfs = DFS(start, n, adj);
    cout << "DFS Traversal: ";
    for (int x : dfs) cout << x << " ";
    cout << endl;

    return 0;
}
