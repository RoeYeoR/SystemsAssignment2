#ifndef MY_MAT_H
#define MY_MAT_H

#include <stdbool.h>

#define SIZE 10

// Function prototypes
void inputMatrix(int graph[SIZE][SIZE]);
bool isValidPath(int graph[SIZE][SIZE], int i, int j);
int shortestPath(int graph[SIZE][SIZE], int i, int j);

#endif 
