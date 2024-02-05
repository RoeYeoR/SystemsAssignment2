#include "my_mat.h"
#include <stdio.h>

int main() {

    int graph[SIZE][SIZE];
    int i, j;
    char action;

    do {
        
        scanf(" %c", &action);  

        switch (action) {
            case 'A':
                
                inputMatrix(graph);

                break;

            case 'B':

                scanf("%d %d", &i, &j);
                printf(isValidPath(graph, i, j) ? "True" : "False");
                break;

            case 'C':
                
                scanf("%d %d", &i, &j);
                int shortest = shortestPath(graph, i, j);
                printf("%d", shortest);
               
                break;

            case 'D':
                
                break;

            default:
            
                break;
        }
    } while (action != 'D');

    return 0;
}
