#include <math.h>
#include <stdio.h>

int main(void) {
  int elementsAmount;

  int isStopped = 0;
  int isStartedAgain = 0;

  const int yesCommand = 1, noCommand = 0;

  while (!isStopped) {

    int playerCommand = 0;
    printf("Start program?\n[1] - yes, [0] - no: ");
    scanf("%d", &playerCommand);

    switch (playerCommand) {
    case yesCommand:
      printf("Enter amount of elements: ");
      scanf("%d", &elementsAmount);
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

      int array[elementsAmount];
      for (int i = 0; i < elementsAmount; i++) {
        printf("Enter element with index %d: ", i);
        scanf("%d", &array[i]);
      }

      int arrayToCheck[elementsAmount];
      for (int i = 0; i < elementsAmount; i++) {
        if (array[i] < 0) {
          arrayToCheck[i] = pow(array[i], 2);
        } else {
          arrayToCheck[i] = array[i];
        }
      }

      int isGrowing = 1;
      for (int i = 0; i < elementsAmount - 1; i++) {
        if (arrayToCheck[i] < arrayToCheck[i + 1]) {
          continue;
        } else {
          isGrowing = 0;
          break;
        }
      }

      if (isGrowing) {
        int product = 1;
        for (int i = 0; i < elementsAmount; i++) {
          product *= array[i];
        }

        printf("Result(product): %d\n", product);
      } else {
        int sum;
        for (int i = 0; i < elementsAmount; i++) {
          sum += array[i];
        }

        printf("Result(sum): %d\n", sum);
      }

      printf("Program execution is complete\n\n");
    }
  }
}