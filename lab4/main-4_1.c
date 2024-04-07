#include "stdio.h"
#include "math.h"

int main(void) {
  int x, y;
  float result;
  
  int is_stop = 0;

  while (is_stop == 0){
    
    printf("\nEnter x: ");
    scanf("%d", &x);
    printf("Enter y: ");
    scanf("%d", &y);

    float denominator0 = pow(x,2) + x*y - pow(y,2);
    float denominator1 = 1 - pow(y,2);
    float denominator2 = 1 + pow(x,2);

    if(denominator0 == 0 || denominator1 == 0 || denominator2 == 0){
      printf("Error: denominator is 0\nPlease try again\n");
      continue;
    }
    else {
      result = ((float)(x + y)/denominator0) + ((float)x / denominator1) + ((float)y / denominator2);
      printf("Result: %.2f\n", result);
    }
  }
}
