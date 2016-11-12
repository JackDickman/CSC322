#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char getGroup(float p) {
  char group;
  if(p >= 0.0 && p < 0.1) group = 'A';
  else if(p >= 0.1 && p < 0.2) group = 'B';
  else if(p >= 0.2 && p < 0.3) group = 'C';
  else if(p >= 0.3 && p < 0.4) group = 'D';
  else if(p >= 0.4 && p < 0.5) group = 'E';
  else if(p >= 0.5 && p < 0.6) group = 'F';
  else if(p >= 0.6 && p < 0.7) group = 'G';
  else if(p >= 0.7 && p < 0.8) group = 'H';
  else if(p >= 0.8 && p < 0.9) group = 'I';
  else if(p >= 0.9 && p < 1.0) group = 'J';
  else if(p >= 1.0 && p < 1.1) group = 'K';
  else if(p >= 1.1 && p < 1.2) group = 'L';
  else if(p >= 1.2 && p < 1.3) group = 'M';
  else if(p >= 1.3 && p < 1.4) group = 'N';
  else if(p >= 1.4 && p < 1.5) group = 'O';
  else if(p >= 1.5 && p < 1.6) group = 'P';
  else if(p >= 1.6 && p < 1.7) group = 'Q';
  else if(p >= 1.7 && p < 1.8) group = 'R';
  else if(p >= 1.8 && p < 1.9) group = 'S';
  else if(p >= 1.9 && p < 2.0) group = 'T';
  else if(p >= 2.0 && p < 2.1) group = 'U';
  else if(p >= 2.1 && p < 2.2) group = 'V';
  else if(p >= 2.2 && p < 2.3) group = 'W';
  else if(p >= 2.3 && p < 2.4) group = 'X';
  else if(p >= 2.4 && p < 2.5) group = 'Y';
  else if(p >= 2.5 && p < 2.6) group = 'Z';
  else group = '!';
  return(group);
}

int main(void) {
  printf("\nEnter depth\t\t: ");
  float depth;
  scanf("%f",&depth);

  printf("Enter percentage O2\t: ");
  float percentage;
  scanf("%f",&percentage);

  float constant = 33.0;

  float ambientpressure = (depth / constant) + 1;

  float partialpressure = (percentage / 100.0) * ambientpressure;

  char group = getGroup(partialpressure);

  printf("\nAmbient Pressure\t: %.1f\n",ambientpressure);
  printf("O2 Pressure\t\t: %.2f\n",partialpressure);
  printf("O2 Group\t\t: %c\n\n",group);

  if(partialpressure >= 1.4) printf("\nExceeds maximal O2 pressure\t: %s\n","true");
  else printf("\nExceeds maximal O2 pressure\t: %s\n","false");
  if(partialpressure >= 1.6) printf("Exceeds contingency O2 pressure\t: %s\n\n","true");
  else printf("Exceeds contingency O2 pressure\t: %s\n\n","false");

  return(EXIT_SUCCESS);
}
