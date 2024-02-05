#include "my_mat.h"
#include <stdio.h>

int main() {
    int graph[SIZE][SIZE];

    // Input matrix values
    printf("Enter the matrix values (10x10):\n");
    inputMatrix(graph);

    // Check if there is a path between two vertices
    int i, j;
    printf("Enter i and j to check if there is a valid path: ");
    scanf("%d %d", &i, &j);
    printf("Path from %d to %d: %s\n", i, j, isValidPath(graph, i, j) ? "True" : "False");

    //  Find the shortest path between two vertices
    printf("Enter i and j to find the shortest path: ");
    scanf("%d %d", &i, &j);
    int shortest = shortestPath(graph, i, j);
    if (shortest == -1) {
        printf("No path exists.\n");
    } else {
        printf("Shortest path from %d to %d: %d\n", i, j, shortest);
    }

    return 0;
}
