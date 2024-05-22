#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void DoubleMatrix(int* matrix, int rows, int columns){
  for(int i = 0; i < rows; i++)
    for(int j = 0; j < columns; j++){
      matrix[i * columns + j] *= 2;
    }
}

void DisplayMatrix(int* matrix, int rows, int columns){

  for(int i = 0; i < rows; i++){
    printf("[ ");
    for(int j = 0; j < columns; j++){
      printf("%d ", matrix[i * columns + j]);
    }
    printf("]\n");
  }
  printf("\n");
}

void RandomizeMatrixValues(int* matrix, int rows, int columns, int Low, int High){
  for(int i = 0; i < rows; i++)
    for(int j = 0; j < columns; j++){
        matrix[i * columns + j] = Low + rand() % High;
    }
}

int main(void) {
  const int Low = -5, High = 10;
  
  int rowsAmount;
  int columnAmount;

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
      printf("Enter amount of rows: ");
      scanf("%d", &rowsAmount);
      printf("Enter amount of columns: ");
      scanf("%d", &columnAmount);
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
