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

bool validateCathetus(void* var) 
{ 
  float value = *(float*)var;
  return value > 0; 
}

int main(void) {
  float a, b;
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
      while(!GetInput("Enter first Cathetus: ", "%f", &a, validateCathetus)){
        printf("Invalid value\nTry Again\n\n");
      }

      while(!GetInput("Enter second Cathetus: ", "%f", &b, validateCathetus)){
        printf("Invalid value\nTry Again\n\n");
      }

      float hypotenuse = sqrt(pow(a,2) + pow(b,2));
      printf("\nHypotenuse: %.2f\n", hypotenuse);

      float area = (a * b) / 2;
      printf("Area: %.2f\n", area);

      printf("Program execution is complete\n\n");
    }
  }
}
