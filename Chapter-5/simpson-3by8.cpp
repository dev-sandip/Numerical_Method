#include <iostream>
#include <math.h>

/* Define function here */
#define f(x) 1 / (1 + pow(x, 2))

using namespace std;
int main()
{
  float lower, upper, integration = 0.0, stepSize, k;
  int i, subInterval;

  /* Input */
  cout << "Enter lower limit of integration: ";
  cin >> lower;
  cout << "Enter upper limit of integration: ";
  cin >> upper;
  cout << "Enter number of sub intervals: ";
  cin >> subInterval;

  /* Calculation */

  /* Finding step size */
  stepSize = (upper - lower) / subInterval;

  /* Finding Integration Value */
  integration = f(lower) + f(upper);

  for (i = 1; i <= subInterval - 1; i++)
  {
    k = lower + i * stepSize;

    if (i % 3 == 0)
    {
      integration = integration + 2 * (f(k));
    }
    else
    {
      integration = integration + 3 * (f(k));
    }
  }
  // All program is same as simpson 1/3 rule except the following formula for integration
  integration = integration * stepSize * 3.0 / 8.0;

  cout << endl
       << "Required value of integration is: " << integration;

  return 0;
}
