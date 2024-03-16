#include <stdio.h>
#include <math.h>

int main(void) {
  int number0, number1;
  int result0, result1, result2;

  printf("Please enter first number:");
  scanf("%d", &number0);
  printf("Please enter first number:");
  scanf("%d", &number1);

  result0 = pow(number0, 2) + pow(number1, 2);
  printf("%s %d\n\n", "\nSum of the squares of your numbers is:", result0);

  result1 = (number0 * number1) * 2;
  printf("%s %d\n\n", "Double product of your numbers:", result1);

  result2 = number0 - number1 * 3;
  printf("%s %d\n", "Difference of the first number and the triple value of the second number is:", result2);
}