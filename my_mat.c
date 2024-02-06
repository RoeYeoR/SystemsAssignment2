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

bool isValidPath(int graph[SIZE][SIZE], int i, int j) {
    return (graph[i][j] > 0 || graph[j][i] > 0);
}

int shortestPath(int graph[SIZE][SIZE], int i, int j) {
    if (i == j) {
        return 0;  
    }

    if (graph[i][j] > 0) {
        return graph[i][j];  
    } else if (graph[j][i] > 0) {
        return graph[j][i];  
    } else {
        // No direct edge, find the shortest path using Dijkstra's algorithm
        int dist[SIZE];
        bool visited[SIZE];

        for (int v = 0; v < SIZE; v++) {
            dist[v] = INT_MAX;
            visited[v] = false;
        }

        dist[i] = 0;

        for (int count = 0; count < SIZE - 1; count++) {
            int u = minDistance(dist, visited);
             if (u == -1) {
                return -1;
            }

            visited[u] = true;

            for (int v = 0; v < SIZE; v++) {
                if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                    dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }

        return (dist[j] == INT_MAX) ? -1 : dist[j];
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
