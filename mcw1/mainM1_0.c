#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

bool GetInt(int* number){
  int result = scanf("%d", number);

  if(result == 1){
    return true;
  }
  return false;
}

bool GetFloat(float* number){
  int result = scanf("%f", number);

  if(result == 1){
    return true;
  }
  return false;
}

int main(void) {
  float x, y;

  int isStopped = 0;
  int isStartedAgain = 0;

  const int yesCommand = 1, noCommand = 0;

  srand(time(0));

  while (!isStopped) {

    int playerCommand = 0;

    do{
      printf("Start program?\n[1] - yes, [0] - no: ");

      if(!GetInt(&playerCommand) 
        || (playerCommand != yesCommand && playerCommand != noCommand)){

        printf("\nInvalid input\n");
        printf("Try Again\n\n");

        while (getchar() != '\n');
      }
      else{ break; }
    } while(true);

    switch (playerCommand) {
    case yesCommand:
      do{
        printf("Enter x: ");

        if(!GetFloat(&x)){

          printf("\nInvalid input\n");
          printf("Try Again\n\n");

          while (getchar() != '\n');
        }
        else{ break; }
      } while(true);
      do{
        printf("Enter y: ");

        if(!GetFloat(&y)){

          printf("\nInvalid input\n");
          printf("Try Again\n\n");

          while (getchar() != '\n');
        }
        else{ break; }
      } while(true);
      break;

    case noCommand:
      isStopped = 1;
      printf("Programm stopped");
      break;

    default:
      isStartedAgain = 1;
      printf("Wrong command\nTry again\n\n");
      break;
    }

    if (isStopped == 1) {
      break;
    } else if (isStartedAgain == 1) {
      isStartedAgain = 0;
      continue;
    } else {

      if((x + y) < 0){
        printf("\n\nCannot calculate\n\n");
      }
      else{
        float result = (pow(x, 2) + pow(y, 2)) / (sqrt(x + y));
        printf("\nResult is: %.2f\n\n", result);
      }

    }
  }
}