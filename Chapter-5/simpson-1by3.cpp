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

    if (i % 2 == 0)
    {
      integration = integration + 2 * (f(k));
    }
    else
    {
      integration = integration + 4 * (f(k));
    }
  }

  integration = integration * stepSize / 3;

  cout << endl
       << "Required value of integration is: " << integration;

  return 0;
}
// Pseudo code for Simpson's 1/3 Rule

// 1. Start

// 2. Define Function f(x)

// 3. Input lower_limit, upper_limit, sub_interval

// 4. Calculate: step_size = (lower_limit - upper_limit)/sub_interval

// 5. Calculate: integration = f(lower_limit) + f(upper_limit)

// 6. Set: i=1

// 7. Loop
//         k= lower_limit + i * step_size

//         If i mod 2 = 0
//         	integration =  integration + 2 * f(k)
//         Else
//         	integration =  integration + 4 * f(k)
//         End If

//         i = i+1

//    While i<= sub_interval

// 8. integration = integration * step_size/3

// 9. Print integration as result

// 10. Stop