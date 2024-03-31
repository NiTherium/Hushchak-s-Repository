#include <stdio.h>

int main(void) {
  int currentSeries;

  printf("Please enter your series: ");
  scanf("%d", &currentSeries);

  switch (currentSeries) {

  case 1:
    printf("Series name: \"The Heirs of the Dragon\"\nPremiere date: August "
           "21, 2022");
    break;
  case 2:
    printf("Series name: \"The Rogue Prince\"\nPremiere date: August 28, 2022");
    break;
  case 3:
    printf("Series name: \"Second of His Name\"\nPremiere date: September 4, "
           "2022");
    break;
  case 4:
    printf("Series name: \"King of the Narrow Sea\"\nPremiere date: September "
           "11, 2022");
    break;
  case 5:
    printf(
        "Series name: \"We Light the Way\"\nPremiere date: September 18, 2022");
    break;
  case 6:
    printf("Series name: \"The Princess and the Queen\"\nPremiere date: "
           "September 25, 2022");
    break;
  case 7:
    printf("Series name: \"Driftmark\"\nPremiere date: October 2, 2022");
    break;
  case 8:
    printf("Series name: \"The Lord of the Tides\"\nPremiere date: October 9, "
           "2022");
    break;
  case 9:
    printf(
        "Series name: \"The Green Council\"\nPremiere date: October 16, 2022");
    break;
  case 10:
    printf("Series name: \"The Black Queen\"\nPremiere date: October 23, 2022");
    break;

  default:
    printf("Your series is not valid");
    break;
  }

  return 0;
}
