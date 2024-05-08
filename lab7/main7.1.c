#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* GetRandomArray(int size){
  const int MIN = -100, MAX = 200;
  
  int array[size];

  for (int i = 0; i < size; i++) {
      array[i] = MIN + rand() % MAX;
    printf("Array[%d] = %d\n", i, array[i]);
  }

  return array;
}

int MinElementIndex(int array[], int size) {

  int min = array[0];
  int index = 0;

  for (int i = 1; i < size; i++) {
    if (array[i] < min) {
      min = array[i];
      index = i;
    }
  }

  return index;
}

void ProductBeforeZero(int array[], int size){
  int zeroIndex = -1;
  int product = 1;

  for (int i = 0; i < size; i++){
    if (array[i] == 0){
      zeroIndex = i;
      break;
    }
    else{
      product *= array[i];
    }
  }

  if(zeroIndex == -1){
    printf("\nThere is no zero in the array\n");
  }
  else if(zeroIndex == 0){
    printf("\nThere is no Elements before zero in the array\n");
  }
  else {
    printf("\nProduct of elements before zero: %d\n", product);
  }
}

int main(void) {
  const int Low = -100, High = 200;

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

      printf("Enter amount of elements: ");
      scanf("%d", &elementsAmount);

      int* arrayGlobal = GetRandomArray(elementsAmount);

      int minIndex = MinElementIndex(arrayGlobal, elementsAmount);
      printf("\nIndex of the minimum element is: %d\n", minIndex);
      ProductBeforeZero(arrayGlobal, elementsAmount);
      
      printf("\nProgram execution is complete\n\n");
    }
  }
}