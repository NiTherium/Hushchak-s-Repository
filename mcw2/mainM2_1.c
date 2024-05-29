#include <math.h>
#include <stdio.h>
#include <stdbool.h>

bool GetInput(char* message, char* format, void* variable, bool(*validate)(void*)) {
    printf("%s", message);
    if (scanf(format, variable) != 1) {
        while (getchar() != '\n');
        return false;
    }
    while (getchar() != '\n');
    return validate(variable);
}

bool validatePlayerCommand(void* var) {
  int value = *(int*)var;
  return value == 1 || value == 0;
}

bool validateValue(void* var) {
  int value = *(int*)var;
  return value > 0;
}

void FillMatrix(int* matrix, int rows, int columns, int maxWidth){
  printf("\nMatrix map [j > i = \"+\"]:\n");
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < columns; j++) {
      if(i < j) {
        matrix[i * columns + j] = i + j;
        printf("%-*s ", maxWidth, "+");
      }
      else if (i == j){
        matrix[i * columns + j] = pow(i, 2) - pow(j, 2); 
        printf("%-*s ", maxWidth, "=");
      }
      else
      { 
        matrix[i * columns + j] = pow(i, 2) - pow(j, 2); 
        printf("%-*s ", maxWidth, "-");
      }
    }
    printf("\n");
  }
  printf("\n");
}

void DisplayMatrix(int* matrix, int rows, int columns, int maxWidth){
  printf("\nMatrix:\n");
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < columns; j++){
      printf("%-*d ", maxWidth, matrix[i * columns + j]);
    }
    printf("\n");
  }
  printf("\n");
}

int main(void) {
  int rowsAmount, columnsAmount;
  const int yesCommand = 1, noCommand = 0;
  
  while (true) {

    int playerCommand = 0;

    while(!GetInput("Start program?\n[1] - yes, [0] - no: ", "%d", &playerCommand, 
      validatePlayerCommand)) {
      printf("Invalid command\n");
    }

    if (playerCommand == noCommand) {
      printf("Program stopped");
      break;
    } else {
      while(!GetInput("Enter rows amount: ", "%d", &rowsAmount, 
        validateValue)){
        printf("Invalid value\n");
      }
      while(!GetInput("Enter columns amount: ", "%d", &columnsAmount, 
        validateValue)){
        printf("Invalid value\n");
      }

      int matrix[rowsAmount][columnsAmount];

      FillMatrix(*matrix, rowsAmount, columnsAmount, 4);
      
      DisplayMatrix(*matrix, rowsAmount, columnsAmount, 4);
      printf("Program execution is complete\n\n");
    }
  }
} 