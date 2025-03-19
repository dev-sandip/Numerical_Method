#include <stdio.h>
#include <stdlib.h>

#define MAX 10 // Maximum matrix size

// Function to input a matrix
void MatrixInput(float matrix[MAX][MAX + 1], int n)
{
  printf("Enter the augmented matrix (coefficients & constants):\n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      printf("matrix[%d][%d] = ", i, j);
      scanf("%f", &matrix[i][j]);
    }
  }
}

// Function to print the matrix
void MatrixPrint(float matrix[MAX][MAX + 1], int n)
{
  printf("\nCurrent Matrix:\n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      printf("%8.4f ", matrix[i][j]);
    }
    printf("\n");
  }
}

// Function to solve the system using Gauss-Jordan elimination
void GaussJordan(float matrix[MAX][MAX + 1], int n)
{
  for (int i = 0; i < n; i++)
  {
    // Make the diagonal element 1 (Pivot Normalization)
    float pivot = matrix[i][i];
    if (pivot == 0.0)
    {
      printf("Mathematical Error: Zero pivot encountered.\n");
      exit(1);
    }
    for (int j = 0; j <= n; j++)
    {
      matrix[i][j] /= pivot;
    }

    // Make other elements in column 0 (Row Reduction)
    for (int k = 0; k < n; k++)
    {
      if (k != i)
      {
        float factor = matrix[k][i];
        for (int j = 0; j <= n; j++)
        {
          matrix[k][j] -= factor * matrix[i][j];
        }
      }
    }
    MatrixPrint(matrix, n); // Display intermediate steps
  }

  // Print the solution
  printf("\nThe solution is:\n");
  for (int i = 0; i < n; i++)
  {
    printf("x[%d] = %0.4f\n", i, matrix[i][n]);
  }
}

int main()
{
  int n;
  float matrix[MAX][MAX + 1];

  printf("Enter the number of equations (n): ");
  scanf("%d", &n);

  if (n > MAX || n <= 0)
  {
    printf("Invalid input! Please enter a value between 1 and %d.\n", MAX);
    return 1;
  }

  MatrixInput(matrix, n);
  printf("\nInitial Augmented Matrix:\n");
  MatrixPrint(matrix, n);

  GaussJordan(matrix, n);

  return 0;
}
