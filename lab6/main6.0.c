#include <math.h>
#include <stdio.h>

int main(void) {
  int rowsAmount;
  int columnAmount;

  int isStopped = 0;
  int isStartedAgain = 0;

  const int yesCommand = 1, noCommand = 0;

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

      printf("\n");
      for (int i = 0; i < rowsAmount; i++){
        for (int j = 0; j < columnAmount; j++){
          printf("Enter number[%d][%d]: ", i, j);
          scanf("%d", &matrix[i][j]);
        }
      }

      printf("\n");
      for (int i = 0; i < rowsAmount; i++){
        printf("[ ");
        for (int j = 0; j < columnAmount; j++){
          printf("%d ", matrix[i][j]);
        }
        printf("]\n");
      }
      printf("\n");

      int firstColumn;
      int secondColumn;

      printf("Index of the first column to be swapped: ");
      scanf("%d", &firstColumn);
      printf("Index of the second column to be swapped: ");
      scanf("%d", &secondColumn);

      if( firstColumn >= 0 && firstColumn < columnAmount && secondColumn >= 0 && secondColumn < columnAmount){
        int boxColumn[columnAmount];

        for (int i = 0; i < columnAmount; i++){
          boxColumn[i] = matrix[i][firstColumn];
        }

        for (int i = 0; i < columnAmount; i++){
          matrix[i][firstColumn] = matrix[i][secondColumn];
        }

        for (int i = 0; i < columnAmount; i++){
          matrix[i][secondColumn] = boxColumn[i];
        }

        printf("\n");
        for (int i = 0; i < rowsAmount; i++){
          printf("[ ");
          for (int j = 0; j < columnAmount; j++){
            printf("%d ", matrix[i][j]);
          }
          printf("]\n");
        }
        printf("\n");
      }
      else{
        printf("\nError: Invalid index\n\n");
      }

      printf("Program execution is complete\n\n");
    }
  }
}