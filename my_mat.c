// my_mat.c

#include "my_mat.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

 void inputMatrix(int graph[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

 int minDistance(int dist[SIZE], bool visited[SIZE]) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < SIZE; v++) {
        if (visited[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}


 void dijkstra(int graph[SIZE][SIZE], int src, int dist[SIZE]) {
    bool visited[SIZE];

    // Initialize distances and visited array
    for (int v = 0; v < SIZE; v++) {
        dist[v] = INT_MAX;
        visited[v] = false;
    }

    // Distance to source node is 0
    dist[src] = 0;

    for (int count = 0; count < SIZE - 1; count++) {
        int u = minDistance(dist, visited);

        // Mark the picked vertex as visited
        visited[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < SIZE; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}

 bool isPathExist(int graph[SIZE][SIZE], int start, int target) {
    int dist[SIZE];
    dijkstra(graph, start, dist);

    // If the target node is reachable, its distance will not be INT_MAX
    return dist[target] != INT_MAX;
}

 int shortestPath(int graph[SIZE][SIZE], int start, int target) {
    int dist[SIZE];
    dijkstra(graph, start, dist);
    
    return dist[target] == INT_MAX ? -1 : dist[target];
}

