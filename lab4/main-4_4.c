#include "math.h"
#include "stdio.h"

int main(void) {

  int is_stop = 0;
  float x, y;

  while (!is_stop){

    printf("Enter a number: ");
    scanf("%f", &x);

    printf(" X       Y\n");
    for(float i = -3; i <= 3; i += 0.5){

      if((x + sqrt(13 * fabs(x))) == 0 ){
        printf("%.2f\t%s\n", x, "null");
        continue;
      }
      else {
        y = (2 + pow(x, 3)) / (x + sqrt(13 * fabs(x)));
      }

      printf("%.2f\t%.2f\n", x, y);

      x += 0.5;
    }

    printf("\n");
    
  }

  return 0;
}
