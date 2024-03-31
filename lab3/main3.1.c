#include <stdio.h>

int main(void) {
  int x1, y1, x2, y2, x3, y3;
  float lineEquation_x, lineEquation_y;

  printf("Please enter the coordinates of the first point: ");
  scanf("%d %d", &x1, &y1);
  printf("Please enter the coordinates of the second point: ");
  scanf("%d %d", &x2, &y2);
  printf("Please enter the coordinates of the third point: ");
  scanf("%d %d", &x3, &y3);

  if (x1 == x2 && x1 == x3) {
    printf("The points lie on the same straight line");
    return 0;
  } else {
    lineEquation_x = (x3 - x1) / (x2 - x1);
  }

  if (y1 == y2 && y1 == y3) {
    printf("The points lie on the same straight line");
    return 0;
  } else {
    lineEquation_y = (y3 - y1) / (y2 - y1);
  }

  if (lineEquation_x == lineEquation_y) {
    printf("The points lie on the same straight line");
  } else {
    printf("The points do NOT lie on the same straight line");
  }

  return 0;
}