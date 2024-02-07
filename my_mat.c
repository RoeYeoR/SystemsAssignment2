
#include "my_mat.h"
#include <stdbool.h>
#include <stdio.h>

 void inputMatrix(int** graph, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}


int dijkstraAlgorithm(int** graph, int start, int dest, const int len) {

    int distFromV[len], counter = 0, min, u;
    bool VisitedV[len];

    //initialize all vertices to max value and bool array to not visited yet.
    for (int i = 0; i < len; i++)
    {
        distFromV[i] = __INT_MAX__;
        VisitedV[i] = false;
    }

    distFromV[start] = 0; // distance from vertex to itself 

    while (++counter < len)
    {
        min = __INT_MAX__;

        
        for (int v = 0; v< len; ++v)
        {
            if (VisitedV[v] || distFromV[v] > min)
                continue;

            min = distFromV[v];
            u = v;
        }

        VisitedV[u] = true;

        //it updates distances if a shorter path is found from the start node (u) to node v.
        for (int v = 0; v < len; v++)
        {
            if (VisitedV[v] || !graph[u][v] || distFromV[u] == __INT_MAX__ || (distFromV[u] + graph[u][v] >= distFromV[v]))
                continue;

            distFromV[v] = distFromV[u] + graph[u][v];
        }
    }

    return distFromV[dest];
}

 bool isPathExist(int** graph, int i, int j, int len) {
      if (graph[i][j]) //first check if exists a direct edge
        return true;

    int res = dijkstraAlgorithm(graph, i, j, len); 

    return (res < __INT_MAX__ && res != 0); //if we found a value smaller than INT_MAX and not zero ,we have valid path
}

 int shortestPath(int** graph, int i, int j, int len) {

   int res = dijkstraAlgorithm(graph, i, j, len);

    return ((res && res != __INT_MAX__) ? res:-1);
}

