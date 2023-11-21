#include "types.h"
#include "user.h"

int **multiply(int **a, int **b, int n)
{

    // Allocate a result matrix
    // Allocate matrix for storing answer
    int **answer = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        answer[i] = (int *)malloc(n * sizeof(int));

    // Multiply the matrix by itself
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            answer[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                answer[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return answer;
}

int ** initMatrix(int n, int r){
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        matrix[i] = (int *)malloc(n * sizeof(int));
    
    //Initialize with some random values 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matrix[i][j] = i * r + j + 1 - r;
        }
    }
    return matrix;
}
int main(int argc, char *argv[])
{
    int n = 128;
    if (argc > 1)
    {
        n = atoi(argv[1]);
    }
    

    for (int i = 0; i < 5; i++)
    {
        // Initialize the matrix
        printf(1, "Initializing Matrix: %d\n", i + 1);
        int **matrix1 = initMatrix(n, i + 1);
        int **matrix2 = initMatrix(n, i + 2);

        // Multiply
        printf(1, "Computing Multiplication: %d\n", i + 1);
        int **ans = multiply(matrix1, matrix2, n);

        printf(1, "Computation finished for Matrix %d with address %p\n", i + 1, ans);
        // free(ans);
        // free(matrix1);
        // free(matrix2);
    }

    exit();
}