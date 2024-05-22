#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

bool GetInt(int* number){
  int result = scanf("%d", number);
  
  if(result == 1){
    return true;
  }
  return false;
}

void RandomizeArrayValues(int* array, int elements, int Low, int High){
  for(int i = 0; i < elements; i++)
    array[i] = Low + rand() % High;
}

void DiplayArray(int* array, int elements){
  printf("\nArray:");
  for(int i = 0; i < elements; i++){
    printf("\n%d", array[i]);
  }
  printf("\n\n");
}

int OddSum(int* array, int elements){
  int sum = 0;

  if(elements <= 2){
    printf("Not enought elements to calculate sum\n\n");
    return 0;
  }
  else{
    for(int i = 0; i < elements; i++){
      if(i % 2 != 0){
        sum += array[i];
      }
    }

    printf("Sum of odd elements: %d\n\n", sum);
    return sum;
  }
}

int SumBetweenPositives(int* array, int elements){
  int sum = 0;
  int indexes[2] = {-1, -1};

  if(elements <= 2){
    printf("Not enought elements to calculate sum\n\n");
    return 0;
  }
  else{
    for(int i = 0; i < elements; i++){
      if(array[i] > 0){
        indexes[0] = i;
        break;
      }
    }
    for(int i = indexes[0] + 1; i < elements; i++){
      if(array[i] > 0){
        indexes[1] = i;
        break;
      }
    }

    if(indexes[0] == -1 || indexes[1] == -1) {
      printf("Not enought Positive elements to calculate sum\n\n");
      return 0;
    }
    else if((indexes[1] - indexes[0]) == 1) {
      printf("Not enought elements to calculate sum\n\n");
      return 0;
    }
    else {
      for(int i = indexes[0] + 1; i < indexes[1]; i++){
        sum += array[i];
      }

      printf("Sum between the first positive elements: %d\n\n", sum);
      return sum;
    }
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

    do{
      printf("Start program?\n[1] - yes, [0] - no: ");

      if(!GetInt(&playerCommand) 
        || (playerCommand != yesCommand && playerCommand != noCommand)){

        printf("\nInvalid input\n");
        printf("Try Again\n\n");

        while (getchar() != '\n');
      }
      else{ break; }
    } while(true);

    switch (playerCommand) {
    case yesCommand:
      do{
        printf("Enter amount of elements: ");

        if(!GetInt(&elementsAmount) 
          || (elementsAmount <= 0)){

          printf("\nInvalid input\n");
          printf("Try Again\n\n");

          while (getchar() != '\n');
        }
        else{ break; }
      } while(true);
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

      RandomizeArrayValues(array, elementsAmount, Low, High);

      DiplayArray(array, elementsAmount);

      int oddSum = OddSum(array, elementsAmount);

      int sumBetweenPositives = SumBetweenPositives(array, elementsAmount);
      
    }
  }
}