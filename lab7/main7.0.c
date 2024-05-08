#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int MinElement(int array[]) {

  int min = array[0];

  for (int i = 1; i < sizeof(array); i++) {
    if (array[i] < min) {
      min = array[i];
    }
  }

  return min;
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

      int arrayGlobal[elementsAmount];

      for (int i = 0; i < elementsAmount; i++) {
        arrayGlobal[i] = Low + rand() % High;
        printf("Array[%d] = %d\n", i, arrayGlobal[i]);
      }

      int minimalElement = MinElement(arrayGlobal);
      printf("\nMinimal array element = %d\n", minimalElement);

      printf("\nProgram execution is complete\n\n");
    }
  }
}