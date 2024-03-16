#include <math.h>
#include <stdio.h>

int main(void) {
  int x, y, z;
  float result;

  float rootExp;

  printf("Please enter your value for x coefficient: ");
  scanf("%d", &x);
  printf("\nPlease enter your value for y coefficient: ");
  scanf("%d", &y);
  printf("\nPlease enter your value for z coefficient: ");
  scanf("%d", &z);

  rootExp = pow(x, 2) * y - 14 * z;
  if (rootExp <= 0) {
    printf("\nThe root are imaginary");
    printf("\nIt is impossible to calculate");
    return 0;
  } else {
    result = sqrt(rootExp);
    printf("\n%s %.2f", "The result is:", result);
    return 0;
  }
}