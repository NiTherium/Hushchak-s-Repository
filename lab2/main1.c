#include <math.h>
#include <stdio.h>

int main(void) {
  int const a = 6, b = 0, c = 11;
  float result;

  result = (a * b + a * c - b * c) / (2 * a - b) - (5 / (a + b));

  printf("\n%s %.2f", "The result is:", result);
  return 0;
}