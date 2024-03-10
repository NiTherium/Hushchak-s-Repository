#include <stdio.h>

int main(void) {
  int number;
  int numberThird, numberFirst;

  printf("\n Please enter your number: ");
  scanf("%d", &number);

  numberThird = number % 10;
  numberFirst = number / 100;

  printf("\nFirst   Third\n");
  printf("number  number\n");
  printf("  %d\t      %d\t\n", numberFirst, numberThird);
  return 0;
}