#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("Enter side of square in km\t: ");
  float side;
  scanf("%f",&side);
  
  printf("Enter road's length in km\t: ");
  float length;
  scanf("%f",&length);
  
  printf("Enter number of 'roos\t\t: ");
  float roos;
  scanf("%f",&roos);

  float width = 10.0 / 1000.0;
  float constant = 1.47;

  float square  = side * side;
  float density = roos / square;
  
  float area = length * width;

  float kills = density * area * constant;

  printf("Expected number of kills is\t: %f\n",kills);

  return(EXIT_SUCCESS);
}
