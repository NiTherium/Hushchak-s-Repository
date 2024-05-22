#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool GetInt(int *number) {
  int result = scanf("%d", number);
  if (result == 1) {
    return true;
  }
  return false;
}

void DoubleMatrix(int *matrix, int rows, int columns) {
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      matrix[i * columns + j] *= 2;
    }
}

void DisplayMatrix(int *matrix, int rows, int columns) {

  for (int i = 0; i < rows; i++) {
    printf("[ ");
    for (int j = 0; j < columns; j++) {
      printf("%d ", matrix[i * columns + j]);
    }
    printf("]\n");
  }
  printf("\n");
}

void RandomizeMatrixValues(int *matrix, int rows, int columns, int Low,
                           int High) {
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      matrix[i * columns + j] = Low + rand() % High;
    }
}

int main(void) {
  const int Low = -5, High = 10;

  int rowsAmount;
  int columnAmount;

  int isStopped = 0;

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
        printf("Enter amount of rows: ");

        if(!GetInt(&rowsAmount) 
          || (rowsAmount <= 0)){

          printf("\nInvalid input\n");
          printf("Try Again\n\n");

          while (getchar() != '\n');
        }
        else{ break; }
      } while(true);
      
      do{
        printf("Enter amount of columns: ");

        if(!GetInt(&columnAmount) 
          || (columnAmount <= 0)){

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
    }

    if (isStopped == 1) {
      break;
    } 
    else {

      int matrix[rowsAmount][columnAmount];

      RandomizeMatrixValues(*matrix, rowsAmount, columnAmount, Low, High);

      printf("\nMatrix before doubling:\n");
      DisplayMatrix(*matrix, rowsAmount, columnAmount);

      DoubleMatrix(*matrix, rowsAmount, columnAmount);

      printf("Matrix after doubling:\n");
      DisplayMatrix(*matrix, rowsAmount, columnAmount);
    }
  }
}
