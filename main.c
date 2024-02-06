#include "my_mat.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    //int graph[SIZE][SIZE] ={0};
    int i, j;
    char action;

    
    int **graph = (int**) malloc(SIZE * sizeof(int*));

    for (int i = 0; i < SIZE; ++i)
        graph[i] = (int*) malloc(SIZE * sizeof(int));

    do {
        
        scanf(" %c", &action);  

        switch (action) {
            case 'A':
                
                inputMatrix(graph,SIZE);

                break;

            case 'B':

                scanf("%d %d", &i, &j);
                printf("%s\n",isPathExist(graph, i, j,SIZE) ? "True" : "False");
                break;

            case 'C':
                
                scanf("%d %d", &i, &j);
                int shortest = shortestPath(graph, i, j,SIZE);
                printf("%d\n", shortest);
               
                break;

            case 'D':
                
                break;

            default:
            
                break;
        }
    } while (action != 'D');

    
    for (int i = 0; i < SIZE; ++i)
        free(graph[i]);

    free(graph);


    return 0;
}
