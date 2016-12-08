#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-------------------------------------------------------------------------------

typedef char String[128];
typedef enum { false, true } bool;
typedef struct node {
  String name;
  struct node * next;
  struct node * friend;
} LLNode;

//-------------------------------------------------------------------------------

LLNode * findFriend(LLNode * head, String name) {
  LLNode * temp = head;

  while(temp->next != NULL) {
    temp = temp->next;
    if(!strcmp(name, temp->name)) {
      return temp;
    }
  }

  return NULL;
}

//-------------------------------------------------------------------------------

bool addNation(LLNode * head, LLNode * newNode) {
  printf("Enter nation name : ");
  scanf("%s", newNode->name);

  if(!strcmp(newNode->name, "quit")) {
    free(newNode);
    return false;
  } else {
    newNode->next = head->next;
    head->next = newNode;
    return true;
  }
}

//-------------------------------------------------------------------------------

void addFriends(LLNode * head) {
  String name;
  LLNode * foundFriend = NULL;
  LLNode * temp = head;

  while(temp->next != NULL) {
    temp = temp->next;
    
    int x = 1;
    while(x == 1) {
      printf("Enter best ally name for %s : ", temp->name);
      scanf("%s", name);

      if(!strcmp(name, temp->name)) {
	printf("You can't be allies with yourself\n");
      } else if((foundFriend = findFriend(head, name)) == NULL) {
	printf("That nation does not exist\n");
      } else {
	x = -1;
      }
    }

    temp->friend = foundFriend;
  }
}

//-------------------------------------------------------------------------------

void print(LLNode * head) {
  int i = 0;
  LLNode * temp;

  while(head->next != NULL) {
    temp = head->next;
    free(head);
    head = temp;
    printf("The best ally of %s is %s\n", head->name, head->friend->name);
  }
  free(head);
}

//-------------------------------------------------------------------------------

int main(void) {
  LLNode * head = malloc(sizeof(LLNode));

  head->next = NULL;

  printf("Enter \'quit\' to stop entering nations\n");

  while(addNation(head, malloc(sizeof(LLNode))));

  if(head->next == NULL) {
    free(head);
    return -1;
  }

  addFriends(head);

  print(head);

  return 0;
}

//-------------------------------------------------------------------------------
