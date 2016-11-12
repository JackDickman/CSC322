#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 128
#define SIZE 1000
#define TRUE 1
#define FALSE 0

typedef int bool;
typedef char String[MAX_STRING];

//----------------------------------------

int main(void) {
  String s1, s2;
  String final = {""};

  printf("Enter first string: ");
  fgets(s1,SIZE,stdin);

  printf("Enter second string: ");
  fgets(s2,SIZE,stdin);

  int position = 0;
  bool stop;
  int i, j;
  for(i = 0; i < strlen(s1) - 1; i++) {
    stop = FALSE;
    final[position] = s1[i];
    position++;
    for(j = 0; (j < strlen(s2) - 1) && (stop == FALSE); j++) {
      if(s1[i] == s2[j]) {
	position--;
	final[position] = final[position + 1];
	stop = TRUE;
      }
    }
  }

  puts(final);
  //printf("%s\n",final);
}
