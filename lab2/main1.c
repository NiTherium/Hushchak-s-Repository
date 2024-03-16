#include <math.h>
#include <stdio.h>

int main(void) {
  int a, b, c;
  float result;

  float denominator0, denominator1;

  printf("Please enter your value for a coefficient: ");
  scanf("%d", &a);
  printf("\nPlease enter your value for b coefficient: ");
  scanf("%d", &b);
  printf("\nPlease enter your value for c coefficient: ");
  scanf("%d", &c);

  denominator0 = 2 * a - b;
  denominator1 = a + b;

  if (denominator0 == 0 || denominator1 == 0) {
    printf("\nDenominator cannot be 0\nIt is impossible to calculate");
    
    return 0;
  }
  else {
    result = ((a * b + a * c - b * c) / (denominator0)) - (5 / denominator1);

    printf("\n%s %.2f", "The result is:", result);
    return 0;
  }
}