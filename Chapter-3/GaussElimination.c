#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void SwapRows(float matrix[][10], int row1, int row2, int cols)
{
  for (int j = 0; j < cols; j++)
  {
    float temp = matrix[row1][j];
    matrix[row1][j] = matrix[row2][j];
    matrix[row2][j] = temp;
  }
}

void GaussElimination(float matrix[][10], int n)
{
  for (int i = 0; i < n; i++)
  {
    // Partial Pivoting
    int maxRow = i;
    for (int k = i + 1; k < n; k++)
    {
      if (fabs(matrix[k][i]) > fabs(matrix[maxRow][i]))
      {
        maxRow = k;
      }
    }
    if (maxRow != i)
    {
      SwapRows(matrix, i, maxRow, n + 1);
    }

    // Check for singular matrix
    if (matrix[i][i] == 0.0)
    {
      printf("Singular matrix detected! No unique solution exists.\n");
      exit(0);
    }

    // Elimination
    for (int j = i + 1; j < n; j++)
    {
      float ratio = matrix[j][i] / matrix[i][i];
      for (int k = 0; k < n + 1; k++)
      {
        matrix[j][k] = matrix[j][k] - ratio * matrix[i][k];
      }
    }
  }
}

void BackSubstitution(float matrix[][10], int n, float x[])
{
  x[n - 1] = matrix[n - 1][n] / matrix[n - 1][n - 1];
  for (int i = n - 2; i >= 0; i--)
  {
    x[i] = matrix[i][n];
    for (int j = i + 1; j < n; j++)
    {
      x[i] = x[i] - matrix[i][j] * x[j];
    }
    x[i] = x[i] / matrix[i][i];
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
  GaussElimination(arr, n);

  // Back Substitution
  float x[n];
  BackSubstitution(arr, n, x);

  // Displaying solution
  PrintSolution(x, n);
  return 0;
}