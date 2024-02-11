#include <stdio.h>

#define MAX_ITEMS 5
#define MAX_WEIGHT 20

int knapSack(int weights[], int values[], int selected_bool[]) {
    int dp[MAX_ITEMS + 1][MAX_WEIGHT + 1];
    int i, w;

    for (i = 0; i <= MAX_ITEMS; i++) {
        for (w = 0; w <= MAX_WEIGHT; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = (values[i - 1] + dp[i - 1][w - weights[i - 1]]) > dp[i - 1][w] ? 
                           (values[i - 1] + dp[i - 1][w - weights[i - 1]]) : dp[i - 1][w];
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    int result = dp[MAX_ITEMS][MAX_WEIGHT];
    int weight = MAX_WEIGHT;
    for (i = MAX_ITEMS; i > 0 && result > 0; i--) {
        if (result == dp[i - 1][weight])
            continue;
        else {
            selected_bool[i - 1] = 1;
            result -= values[i - 1];
            weight -= weights[i - 1];
        }
    }

    return dp[MAX_ITEMS][MAX_WEIGHT];
}

int main() {

 int weights[MAX_ITEMS], values[MAX_ITEMS], selected_bool[MAX_ITEMS] = {0};

 char items[MAX_ITEMS];

    for (int i = 0; i < MAX_ITEMS; i++) 
    {

        scanf(" %c %d %d", &items[i], &values[i], &weights[i]);

    }


    int max_value = knapSack(weights, values, selected_bool);

    printf("Maximum profit: %d\n", max_value);

    printf("Selected items:");

    for (int i = 0; i < MAX_ITEMS; i++) {

        if (selected_bool[i])

            printf(" %c", items[i]);

    }

   



    return 0;
}
