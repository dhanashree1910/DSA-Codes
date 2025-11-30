/*Write a Program to implement Dijkstra’s algorithm to find shortest distance 
between two nodes of a user defined graph. Use Adjacency Matrix to represent a 
graph*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int findMinvertex(vector<int> &dist, vector<bool> &visited, int n)
{
    int minvertex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (minvertex == -1 || dist[i] < dist[minvertex]))
        {
            minvertex = i;
        }
    }
    return minvertex;
}
void dijkstras(vector<vector<int>> &graph, int src, int n)
{

    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);

    dist[src] = 0;

    for (int i = 0; i < n; i++)
    {
        int u = findMinvertex(dist, visited, n);
        visited[u] = true;

        for (int v = 0; v < n; v++)
        { 
            if (graph[u][v] && !visited[v] && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    cout << "Shortest distance from vertex " << src << ":" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << src << " -> " << i << " = " << dist[i] << endl;
    }
}
int main()
{
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}};

    dijkstras(graph, 0, 5);
}
