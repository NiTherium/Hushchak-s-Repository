#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

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

void FillArrayRandomly(float* array, int size, int Low, int High){
  for (int i = 0; i < size; i++){
    array[i] = (float)(Low + rand() % High) / 100;
  }
}

void DisplayArray(float* array, int size){
  printf("Array: ");
  for (int i = 0; i < size; i++){
    printf("|%.2f| ", array[i]);
  }
  printf("\n");
}

int SumOfOddIndexElements(float* array, int size){
  float sum = 0;

  if(size <= 3){
    printf("Not enought elemets to calculate sum\n");
    return 0;
  }
  else{
    for(int i = 1; i < size; i += 2){
      sum += array[i];
    }

    printf("Sum of elements with Odd indexes is: %.2f\n", sum);
    return sum;
  }
}

int main(void) {
  const int LOW = -10000, HIGH = 20001;

  int elementsAmount;
  const int yesCommand = 1, noCommand = 0;

  srand(time(0));

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
      while(!GetInput("Enter elements amount: ", "%d", &elementsAmount, 
        validateValue)){
        printf("Invalid value\n");
      }

      float array[elementsAmount];

      FillArrayRandomly(array, elementsAmount, LOW, HIGH);
      DisplayArray(array, elementsAmount);

      float oddSum = SumOfOddIndexElements(array, elementsAmount);
      printf("\nProgram execution is complete\n\n");
    }
  }
} 