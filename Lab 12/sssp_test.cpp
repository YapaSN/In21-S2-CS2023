#include <iostream>
#include <limits.h>
// #include <stdio.h>

#define SIZE 6

using namespace std;

// Function to return the nearest neighbor of a vertex
int nearestNeighbor(int distances[], bool visited[])
{
    int min = INT_MAX, nearestIndex;

    for (int i = 0; i < SIZE; i++)
        if (visited[i] == false && distances[i] <= min)
            min = distances[i], nearestIndex = i;

    return nearestIndex;
}

// Function to display times to each city from the source
int DisplayTimes(int source, int distances[], int n)
{
    int sum = 0;
    double average;

    for(int i = 0; i < SIZE; i++){
        sum += distances[i];
    }
    average = (double)sum/(double)(SIZE - 1);

    cout << "Distances from Source " << source << endl;
    for (int i = 0; i < SIZE; i++){
        if(i == source){
            continue;
        }
        cout << "City " << i << ": " << distances[i] << endl;
    }

    cout << "\nAverage Time: " << average << endl;

}

void dijkstra(int graph[SIZE][SIZE], int source){
    int distances[SIZE];
    bool visited[SIZE];

    // Initialize distances array values to infinity.
    for (int i = 0; i < SIZE; i++)
        distances[i] = INT_MAX, visited[i] = false;

    // Set up distance from source to itself to zero
    distances[source] = 0;

    // Find shortest path for all vertices
    for (int city = 0; city < SIZE - 1; city++) {
        // Get the nearest unvisited city
        int j = nearestNeighbor(distances, visited);

        visited[j] = true;

        for (int i = 0; i < SIZE; i++){
            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!visited[i] && graph[j][i] && distances[j] != INT_MAX && distances[j] + graph[j][i] < distances[i])
            distances[i] = distances[j] + graph[j][i];
        }
    }


    DisplayTimes(source, distances, SIZE);
}



int main()
{
    int graph[SIZE][SIZE] = {
        {0,10,0,0,15,5},
        {10,0,10,30,0,0},
        {0,10,0,12,5,0},
        {0,30,12,0,0,20},
        {15,0,5,0,0,0},
        {5,0,0,20,0,0}};
    int source;

    cout << "Source city: ";
    cin >> source;

    dijkstra(graph, source);

    return 0;
}