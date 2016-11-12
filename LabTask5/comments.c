#include <stdio.h>
#include <stdlib.h>

int main(void) {
  
  int c;

  while((c = getchar()) != EOF) {
    if(c == '/') {
      if((c = getchar()) == '/') {
	while((c = getchar()) != '\n') {
	  printf("%c",c);
	}
	printf("\n");
      }
      else if(c == '*') {
	while((c = getchar()) != '*') {
	  printf("%c",c);
	}
	printf("\n");
      }
    }
  }

  return(EXIT_SUCCESS);
}
