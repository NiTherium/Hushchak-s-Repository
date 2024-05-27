#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
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

bool validateFloat(void* var) { return true; }

int main(void) {
  float x, y;
  const int yesCommand = 1, noCommand = 0;

  srand(time(0));

  while (true) {

    int playerCommand = 0;

    while(!GetInput("Start program?\n[1] - yes, [0] - no: ", "%d", &playerCommand, 
      validatePlayerCommand)) {
      printf("Invalid command\nTry Again\n\n");
    }

    if (playerCommand == noCommand) {
      printf("Program stopped");
      break;
    } else {
      while(!GetInput("Enter x: ", "%f", &x, validateFloat)){
        printf("Invalid value\nTry Again\n\n");
      }

      while(!GetInput("Enter y: ", "%f", &y, validateFloat)){
        printf("Invalid value\nTry Again\n\n");
      }

      if((x + y) <= 0){
        printf("\nCannot calculate with this parameter values\n\n");
      }
      else{
        float result = (pow(x, 2) + pow(y, 2)) / (sqrt(x + y));
        printf("\nResult is: %.2f\n", result);
        
        printf("Program execution is complete\n\n");
      }
    }
  }
}
