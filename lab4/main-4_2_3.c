#include "math.h"
#include "stdio.h"

int main(void) {
  int suma = 0;
  int result;

  int i = 1;

  do {
    if (i % 2 == 0) {
      suma += i;
    }

    i++;
    
  } while (i <= 10);

  result = pow(suma, 2);
  printf("%s %d", "Result:", result);

  return 0;
}
