#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  const int Low = -100, High = 200;

  int isStopped = 0;
  int isStartedAgain = 0;

  const int yesCommand = 1, noCommand = 0;

  int playerCommand;
  srand(time(0));

  while (!isStopped) {

    playerCommand = 0;
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

      int elementsAmount;

      printf("Enter amount of elements: ");
      scanf("%d", &elementsAmount);

      int array[elementsAmount];
      
      playerCommand = 0;
      printf("Randomize numbers?\n[1] - yes, [0] - no: ");
      scanf("%d", &playerCommand);

      switch (playerCommand) {
      case yesCommand:
        for (int i = 0; i < elementsAmount; i++) {
          array[i] = Low + rand() % High;
          printf("%d\n", array[i]);
        }
        break;

      case noCommand:
        for (int i = 0; i < elementsAmount; i++) {
          printf("Enter element with index %d: ", i);
          scanf("%d", &array[i]);
        }
        break;

      default:
        isStartedAgain = 1;
        printf("Wrong command\nTry again\n\n");
        break;
      }

      if (isStartedAgain) {
        isStartedAgain = 0;
        continue;
      } else {
        int maxAbs = 0;
        for (int i = 0; i < elementsAmount; i++) {
          if (abs(array[i]) > maxAbs) {
            maxAbs = abs(array[i]);
          }
        }
        printf("Max absolute value of array: %d\n", maxAbs);

        int sum = 0;
        int zeroIndex = -1;
        for (int i = 0; i < elementsAmount; i++) {
          if (array[i] == 0) {
            zeroIndex = i;
          }
        }

        if (zeroIndex < 0) {
          printf("There is no zero in array\n");
        } else {
          for (int i = zeroIndex; i < elementsAmount; i++) {
            sum += array[i];
          }
          printf("Sum of elements after zero: %d\n", sum);
        }
      }

      printf("Program execution is complete\n\n");
    }
  }
}