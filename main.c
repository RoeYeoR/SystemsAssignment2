#include "my_mat.h"
#include <stdio.h>

int main() {
    int graph[SIZE][SIZE];

    // Step A: Input matrix values
    printf("Enter the matrix values (10x10):\n");
    inputMatrix(graph);

    char action;

    do {
        printf("Choose an action (A, B, C, D): ");
        scanf(" %c", &action);  // Note the space before %c to consume the newline character

        switch (action) {
            case 'A':
                // Perform function #1
                // Modify or call the function you want to execute for action A
                printf("Performing function #1...\n");
                break;

            case 'B':
                // Perform function #2
                // Modify or call the function you want to execute for action B
                printf("Performing function #2...\n");
                break;

            case 'C':
                // Perform function #3
                // Modify or call the function you want to execute for action C
                printf("Performing function #3...\n");
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
