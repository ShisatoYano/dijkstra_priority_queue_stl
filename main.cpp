#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

// pair
typedef pair<int, int> i_pair;

// add an edge
void add_edge(vector<pair<int, int>> adj[], int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

// print shortest path from src to all other vertices
void shortest_path(vector<pair<int, int>> adj[], int V, int src) {
    // create a priority queue
    priority_queue<i_pair, vector<i_pair>, greater<i_pair>> pq;

    // create a vector for distances
    // initialize all distances as infinite(INF)
    vector<int> dist(V, INF);

    // insert source itself in priority queue
    // initialize its distance as 0
    pq.push(make_pair(0, src)); // (distance, vertex)
    dist[src] = 0;

    // looping till priority queue become empty
    // or all distances are not finalized
    while (!pq.empty()) {
        // first vertex in pair is the minimum distance vertex
        // extract it from priority queue
        int u = pq.top().second;
        pq.pop();

        // get all adjacent of u
        for (auto x : adj[u]) {
            int v = x.first;
            int w = x.second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main() {
    int V = 9;
    vector<i_pair> adj[V];

    add_edge(adj, 0, 1, 4);
    add_edge(adj, 0, 7, 8);
    add_edge(adj, 1, 2, 8);
    add_edge(adj, 1, 7, 11);
    add_edge(adj, 2, 3, 7);
    add_edge(adj, 2, 8, 2);
    add_edge(adj, 2, 5, 4);
    add_edge(adj, 3, 4, 9);
    add_edge(adj, 3, 5, 14);
    add_edge(adj, 5, 6, 2);
    add_edge(adj, 6, 7, 1);
    add_edge(adj, 6, 8, 6);
    add_edge(adj, 7, 8, 7);

    shortest_path(adj, V, 0);

    return 0;
}
