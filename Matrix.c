#include <stdio.h>

int main() {
    int a[10][10], b[10][10], c[10][10];
    int r1, c1, r2, c2, i, j, k;
    int choice;

    do {
        printf("\n----- MATRIX OPERATIONS -----\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Matrix Transpose\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch(choice) {

        case 1:
            // MATRIX ADDITION
            printf("Enter rows and columns of matrices: ");
            scanf("%d %d", &r1, &c1);

            printf("Enter elements of Matrix A:\n");
            for(i=0; i<r1; i++)
                for(j=0; j<c1; j++)
                    scanf("%d", &a[i][j]);

            printf("Enter elements of Matrix B:\n");
            for(i=0; i<r1; i++)
                for(j=0; j<c1; j++)
                    scanf("%d", &b[i][j]);

            printf("\nResult: Matrix A + B =\n");
            for(i=0; i<r1; i++) {
                for(j=0; j<c1; j++) {
                    c[i][j] = a[i][j] + b[i][j];
                    printf("%d ", c[i][j]);
                }
                printf("\n");
            }
            break;

        case 2:
            // MATRIX MULTIPLICATION
            printf("Enter rows and columns of Matrix A: ");
            scanf("%d %d", &r1, &c1);

            printf("Enter rows and columns of Matrix B: ");
            scanf("%d %d", &r2, &c2);

            if(c1 != r2) {
                printf("Multiplication not possible! Columns of A must equal rows of B.\n");
                break;
            }

            printf("Enter elements of Matrix A:\n");
            for(i=0; i<r1; i++)
                for(j=0; j<c1; j++)
                    scanf("%d", &a[i][j]);

            printf("Enter elements of Matrix B:\n");
            for(i=0; i<r2; i++)
                for(j=0; j<c2; j++)
                    scanf("%d", &b[i][j]);

            // Initialize result matrix to 0
            for(i=0; i<r1; i++)
                for(j=0; j<c2; j++)
                    c[i][j] = 0;

            // Correct multiplication logic
            for(i=0; i<r1; i++)
                for(j=0; j<c2; j++)
                    for(k=0; k<c1; k++)
                        c[i][j] += a[i][k] * b[k][j];

            printf("\nResult: Matrix A × B =\n");
            for(i=0; i<r1; i++) {
                for(j=0; j<c2; j++)
                    printf("%d ", c[i][j]);
                printf("\n");
            }
            break;

        case 3:
            // MATRIX TRANSPOSE
            printf("Enter rows and columns of Matrix: ");
            scanf("%d %d", &r1, &c1);

            printf("Enter elements:\n");
            for(i=0; i<r1; i++)
                for(j=0; j<c1; j++)
                    scanf("%d", &a[i][j]);

            printf("\nTranspose of the Matrix:\n");
            for(i=0; i<c1; i++) {
                for(j=0; j<r1; j++)
                    printf("%d ", a[j][i]);
                printf("\n");
            }
            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice! Try again.\n");
        }

    } while(choice != 4);

 return 0;
}