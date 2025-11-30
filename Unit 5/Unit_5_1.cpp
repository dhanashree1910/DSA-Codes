/* Write a Program to accept a graph from a user and represent it with Adjacency 
Matrix and perform BFS and DFS traversals on it. */

#include <iostream>
#include <queue>
using namespace std;

void BFS(int adj[20][20], int n, int start) {
    int visited[20] = {0};
    queue<int> q;

    visited[start] = 1;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        // check all neighbours
        for (int i = 1; i <= n; i++) {
            if (adj[node][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
    cout << endl;
}

void DFS_Recursive(int node, int adj[20][20], int visited[], int n) {
    visited[node] = 1;
    cout << node << " ";

    for (int i = 1; i <= n; i++) {
        if (adj[node][i] == 1 && visited[i] == 0) {
            DFS_Recursive(i, adj, visited, n);
        }
    }
}

void DFS(int adj[20][20], int n, int start) {
    int visited[20] = {0};
    cout << "DFS Traversal: ";
    DFS_Recursive(start, adj, visited, n);
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int adj[20][20];
    cout << "Enter adjacency matrix:\n";

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    BFS(adj, n, start);
    DFS(adj, n, start);

    return 0;
}
