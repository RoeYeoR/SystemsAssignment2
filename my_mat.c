// my_mat.c

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


int dijkstraAlgorithm(int** m, int start, int vert_to_find, const int len) {

    int distFromV[len], counter = 0, min, u;
    bool VisitedV[len];

    for (int i = 0; i < len; i++)
    {
        distFromV[i] = __INT_MAX__;
        VisitedV[i] = false;
    }

    distFromV[start] = 0;

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

        for (int v = 0; v < len; v++)
        {
            if (VisitedV[v] || !m[u][v] || distFromV[u] == __INT_MAX__ || (distFromV[u] + m[u][v] >= distFromV[v]))
                continue;

            distFromV[v] = distFromV[u] + m[u][v];
        }
    }

    return distFromV[vert_to_find];
}

 bool isPathExist(int** graph, int i, int j, int len) {
      if (graph[i][j])
        return true;

    int res = dijkstraAlgorithm(graph, i, j, len);

    return (res < __INT_MAX__ && res != 0);
}

 int shortestPath(int** graph, int i, int j, int len) {

   int res = dijkstraAlgorithm(graph, i, j, len);

    return ((res && res != __INT_MAX__) ? res:-1);
}

