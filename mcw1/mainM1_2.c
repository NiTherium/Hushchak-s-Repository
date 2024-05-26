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

bool validateSalary(void* var) 
{ 
  float value = *(float*)var;
  return value > 0; 
}

bool validatePercents(void* var) 
{ 
  float value = *(float*)var;
  return value >= 0 && value <= 100; 
}

int main(void) {
  float salary, tax;
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
      while(!GetInput("Enter the amount of the worker's salary: ", "%f", &salary, 
        validateSalary)){
        printf("Invalid value\nTry Again\n\n");
      }

      while(!GetInput("Enter the percentage of the tax: ", "%f", &tax, 
        validatePercents)){
        printf("Invalid value\nTry Again\n\n");
      }

      float taxableSalary = salary - (salary * tax / 100);
      printf("Taxable salary: %.2f\n", taxableSalary);

      printf("Program execution is complete\n\n");
    }
  }
}
