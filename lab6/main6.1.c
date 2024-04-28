#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {
  const int Low = 0, High = 2;
  
  int elementsAmount;

  int isStopped = 0;
  int isStartedAgain = 0;

  const int yesCommand = 1, noCommand = 0;

  srand(time(0));

  while (!isStopped) {

    int playerCommand = 0;
    printf("Start program?\n[1] - yes, [0] - no: ");
    scanf("%d", &playerCommand);

    switch (playerCommand) {
    case yesCommand:
      printf("Enter amount of rows and columns: ");
      scanf("%d", &elementsAmount);
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

      int matrix[elementsAmount][elementsAmount];

      for (int i = 0; i < elementsAmount; i++){
        for (int j = 0; j < elementsAmount; j++){
            matrix[i][j] = Low + rand() % High;
        }
      }

      printf("\n");
      for (int i = 0; i < elementsAmount; i++){
        printf("[ ");
        for (int j = 0; j < elementsAmount; j++){
          printf("%d ", matrix[i][j]);
        }
        printf("]\n");
      }
      printf("\n");

      int magicalSquare = 0;

      for (int i = 0; i < (elementsAmount - 1); i++){
        int sumFirst = 0;
        int sumSecond = 0;
        
        for (int j = 0; j < elementsAmount; j++){
            sumFirst += matrix[i][j];
        }
        for (int j = 0; j < elementsAmount; j++){
            sumSecond += matrix[i + 1][j];
        }

        if(sumFirst != sumSecond){
          magicalSquare = 1;
          break;
        }
      }

      if(magicalSquare != 1){
        for (int i = 0; i < (elementsAmount - 1); i++){
          int sumFirst = 0;
          int sumSecond = 0;

          for (int j = 0; j < elementsAmount; j++){
              sumFirst += matrix[j][i];
          }
          for (int j = 0; j < elementsAmount; j++){
              sumSecond += matrix[j][i + 1];
          }

          if(sumFirst != sumSecond){
            magicalSquare = 1;
            break;
          }
        }
      }

      if(magicalSquare == 1){
        printf("Not magical square\n\n");
      }
      else{
        printf("Magical square\n\n");
      }
      
      printf("Program execution is complete\n\n");
    }
  }
}