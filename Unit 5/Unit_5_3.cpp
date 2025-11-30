#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> prims(vector<vector<int>> &vec, int vertices, int edges) {

    // Create adjacency list
    unordered_map<int, list<pair<int,int>>> adj; // (node → list of {neighbour, weight})

    for (int i = 0; i < edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected
    }

    vector<int> key(vertices, INT_MAX);  // weight to reach each node
    vector<bool> inMST(vertices, false); // included in MST or not
    vector<int> parent(vertices, -1);    // store MST edges

    set<pair<int,int>> st;   // (key, node)

    key[0] = 0;
    st.insert({0, 0});       // start with node 0

    while (!st.empty()) {

        auto top = *st.begin();
        st.erase(st.begin());

        int u = top.second;
        inMST[u] = true;

        // check neighbours
        for (auto nbr : adj[u]) {
            int v = nbr.first;
            int w = nbr.second;

            if (!inMST[v] && w < key[v]) {

                auto record = st.find({key[v], v});
                if (record != st.end())
                    st.erase(record);

                key[v] = w;
                parent[v] = u;
                st.insert({key[v], v});
            }
        }
    }

    // Return MST edges as pairs
    vector<pair<int,int>> mst;
    for (int i = 1; i < vertices; i++) {
        mst.push_back({parent[i], i});
    }
    return mst;
}

int main() {
    vector<vector<int>> edges = {
        {0,1,2},
        {0,4,4},
        {1,4,7},
        {1,3,2},
        {1,2,5},
        {2,3,6},
        {3,4,1}
    };

    int v = 5;
    int e = 7;

    vector<pair<int,int>> mst = prims(edges, v, e);

    cout << "Minimum Spanning Tree edges:\n";
    for (auto &p : mst) {
        cout << p.first << " - " << p.second << endl;
    }

    return 0;
}
