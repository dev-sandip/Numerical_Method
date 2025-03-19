#include <stdio.h>
#include <stdlib.h>

// Function to input the augmented matrix
void InputMatrix(float matrix[][10], int rows, int cols, const char *message)
{
  printf("%s\n", message);
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      scanf("%f", &matrix[i][j]);
    }
  }
}

// Function to print the matrix
void PrintMatrix(float matrix[][10], int rows, int cols)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      printf("%f ", matrix[i][j]);
    }
    printf("\n");
  }
}

// Function to swap two rows of the matrix
void SwapRows(float matrix[][10], int row1, int row2, int cols)
{
  for (int j = 0; j < cols; j++)
  {
    float temp = matrix[row1][j];
    matrix[row1][j] = matrix[row2][j];
    matrix[row2][j] = temp;
  }
}
void PrintSolution(float x[], int n)
{
  printf("\nSolution:\n");
  for (int i = 0; i < n; i++)
  {
    printf("x%d = %f\n", i + 1, x[i]);
  }
}
int main()
{
  int n;
  printf("Enter the number of equations: ");
  scanf("%d", &n);
  float arr[n][10]; // Augmented matrix
  InputMatrix(arr, n, n + 1, "Enter the elements of augmented matrix:");
  printf("Augmented Matrix:\n");
  PrintMatrix(arr, n, n + 1);

  // Perform Gauss Elimination
  for (int i = 0; i < n; i++)
  {
    // Check if the diagonal element is zero
    if (arr[i][i] == 0.0)
    {
      // Find a row below to swap with
      int swapRow = -1;
      for (int k = i + 1; k < n; k++)
      {
        if (arr[k][i] != 0.0)
        {
          swapRow = k;
          break;
        }
      }
      if (swapRow == -1)
      {
        printf("Singular matrix detected! No unique solution exists.\n");
        return 0;
      }
      // Swap rows using the SwapRows function
      SwapRows(arr, i, swapRow, n + 1);
    }

    // Elimination
    for (int j = i + 1; j < n; j++)
    {
      float ratio = arr[j][i] / arr[i][i];
      for (int k = 0; k <= n; k++)
      {
        arr[j][k] = arr[j][k] - ratio * arr[i][k];
      }
    }
  }

  // Back Substitution
  float x[n];
  x[n - 1] = arr[n - 1][n] / arr[n - 1][n - 1];
  for (int i = n - 2; i >= 0; i--)
  {
    x[i] = arr[i][n];
    for (int j = i + 1; j < n; j++)
    {
      x[i] = x[i] - arr[i][j] * x[j];
    }
    x[i] = x[i] / arr[i][i];
  }

  PrintSolution(x, n);
  return 0;
}