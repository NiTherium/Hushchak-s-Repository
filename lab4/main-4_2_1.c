#include "math.h"
#include "stdio.h"

int main(void) {
  int suma = 0;
  int result;

  for (int i = 1; i <= 10; i++) {
    
    if (i % 2 == 0) {
      suma += i;
    } else {
      continue;
    }
  }

  result = pow(suma, 2);
  printf("%s %d", "Result:", result);

  return 0;
}
