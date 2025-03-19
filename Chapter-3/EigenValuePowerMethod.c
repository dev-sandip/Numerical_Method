#include <stdio.h>
#include <math.h>

#define MAX 10

void MatrixInput(float matrix[MAX][MAX], int rows, int cols, const char *message)
{
  printf("%s\n", message);
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      printf("matrix[%d][%d] = ", i, j);
      scanf("%f", &matrix[i][j]);
    }
  }
}

void MatrixPrint(float matrix[MAX][MAX], int rows, int cols)
{
  printf("\nMatrix:\n");
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      printf("%0.4f ", matrix[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  float arr[MAX][MAX], x[MAX], y[MAX], lambda = 0, lambda_old;
  int i, j, n;
  const float error = 0.0001;

  printf("Enter the size of matrix (n x n): ");
  scanf("%d", &n);

  if (n > MAX || n <= 0)
  {
    printf("Invalid matrix size. Please enter a size between 1 and %d.\n", MAX);
    return 1;
  }

  MatrixInput(arr, n, n, "Enter the matrix elements:");
  MatrixPrint(arr, n, n);

  // Initialize x to all 1s
  for (i = 0; i < n; i++)
    x[i] = 1;

  do
  {
    // Compute y = A * x
    for (i = 0; i < n; i++)
    {
      y[i] = 0;
      for (j = 0; j < n; j++)
      {
        y[i] += arr[i][j] * x[j];
      }
    }

    // Compute lambda (Rayleigh quotient)
    lambda_old = lambda;
    lambda = 0;
    for (i = 0; i < n; i++)
      lambda += y[i] * x[i];

    // Normalize y to get the next x
    float norm = sqrt(lambda);
    for (i = 0; i < n; i++)
      x[i] = y[i] / norm;

  } while (fabs(lambda - lambda_old) > error);

  printf("\nThe Eigenvalue is: %0.6f\n", lambda);
  printf("The Eigenvector is:\n");
  for (i = 0; i < n; i++)
  {
    printf("%0.6f\n", x[i]);
  }

  return 0;
}
