#include "my_mat.h"
#include <stdio.h>

int main() {
    int graph[SIZE][SIZE];

   

    char action;

    do {
        printf("Choose an action (A, B, C, D): ");
        scanf(" %c", &action);  // Note the space before %c to consume the newline character

        switch (action) {
            case 'A':
                printf("Enter the matrix values (10x10):\n");
                inputMatrix(graph);

                break;

            case 'B':
                 int i, j;
                printf("Enter i and j to check if there is a path: ");
                scanf("%d %d", &i, &j);
                printf("Path from %d to %d: %s\n", i, j, isValidPath(graph, i, j) ? "True" : "False");
                break;

            case 'C':
                printf("Enter i and j to find the shortest path: ");
                scanf("%d %d", &i, &j);
                int shortest = shortestPath(graph, i, j);
                if (shortest == -1) {
                printf("No path exists.\n");
                } else {
                printf("Shortest path from %d to %d: %d\n", i, j, shortest);
                }
                break;

            case 'D':
                // Exit the program
                printf("Exiting the program...\n");
                break;

            default:
                printf("Invalid action. Please choose A, B, C, or D.\n");
                break;
        }
    } while (action != 'D');

    return 0;
}
