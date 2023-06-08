#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Function to add an edge to the graph
void addEdge(vector<vector<pair<int, int>>>& graph, int src, int dest, int weight) {
    graph[src].push_back(make_pair(dest, weight));
    graph[dest].push_back(make_pair(src, weight));
}

// Function to find the minimum spanning tree using Prim's algorithm
void primMST(vector<vector<pair<int, int>>>& graph, int startNode) {
    int numVertices = graph.size();

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> parent(numVertices, -1);

    vector<int> key(numVertices, INT_MAX);

    vector<bool> inMST(numVertices, false);

    pq.push(make_pair(0, startNode));
    key[startNode] = 0;

    int mstWeight = 0;

    while (!pq.empty()) {
        // Extract the vertex with the minimum key value from the priority queue
        int u = pq.top().second;
        pq.pop();

        // Include the extracted vertex in the MST
        inMST[u] = true;

        // Add the weight of the edge to the MST weight
        mstWeight += key[u];

        // Iterate through all adjacent vertices of u
        for (auto it = graph[u].begin(); it != graph[u].end(); ++it) {
            int v = it->first;
            int weight = it->second;

            // If v is not in MST and weight of (u,v) is smaller than current key of v
            if (inMST[v] == false && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                
                pq.push(make_pair(key[v], v));
            }
        }
    }

    // Print the edges of the MST
    cout << "Minimum Spanning Tree Edges:" << endl;
    for (int i = 1; i < numVertices; ++i)
        cout << parent[i] << " - " << i << endl;

    // Print the weight of the MST
    cout << "Weight of the Minimum Spanning Tree: " << mstWeight << endl;
}

int main() {
    int numVertices = 6;
    int startNode = 0;
    
    vector<vector<pair<int, int>>> graph(numVertices);

    addEdge(graph, 0, 1, 3);
    addEdge(graph, 0, 5, 1);
    addEdge(graph, 1, 2, 2);
    addEdge(graph, 1, 3, 1);
    addEdge(graph, 1, 4, 10);
    addEdge(graph, 2, 3, 3);
    addEdge(graph, 2, 5, 5);
    addEdge(graph, 3, 4, 5);
    addEdge(graph, 4, 5, 4);

    primMST(graph,startNode);

}