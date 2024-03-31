#include <stdio.h>

int main(void) {
  int x, z;
  float result;

  printf("Please enter x:");
  scanf("%d", &x);
  printf("Please enter z:");
  scanf("%d", &z);

  if (x == 5) {
    result = 3 + x * z;
    printf("%s %.1f", "Result:", result);

    return 0;
  }
  if (x == -5) {
    result = (float)(x + z) / (float)(7 - z);
    printf("%s %.1f", "Result:", result);

    return 0;
  }
  if (x == 0) {
    result = x;
    printf("%s %.1f", "Result:", result);

    return 0;
  }

  if (x != 5 && x != -5 && x != 0) {
    printf("Impossible to calculate");

    return 0;
  }

  return 0;
}
