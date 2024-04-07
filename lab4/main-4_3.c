#include "math.h"
#include "stdio.h"

int main(void) {
  int n;
  float x;

  float suma;
  int localSuma;

  int is_stop = 0;

  while (!is_stop) {

    suma = 0;

    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter x: ");
    scanf("%f", &x);

    for (int i = 1; i <= n; i++) {
      localSuma = 0;

      for (int j = 2; j <= n; j++) {
        localSuma += x + i * j;
      }

      suma += localSuma;
    }

    printf("Suma: %.2f\n\n", suma);
  }
}
