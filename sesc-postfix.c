#include <stdio.h>
#include <stdlib.h>
#include "postfix.h"

int error1(Node **head){
  if ((*head)==NULL) {
    printf("empty");
    printf("\n");
    exit(0);      
  }
}

int error2(Node **head){
Node *hea = (*head)->next;
  if ((*hea)==NULL) {
    printf("empty");
    printf("\n");
    exit(0);      
  }
}

int main(void) {
  Node *head= NULL;
  char str;
  scanf("%c", &str);
  for( ;str != '\n'; ){
    scanf("%c", &str);
    if (str <= '9' && str >= '0')
      push_front(&head, str);
    if (str == '~') {
      error1(&head);     
      int x = -(pop_front(&head));
      push_front(&head, x);
    }
    if (str == '+') {
      error2(&head);      
      int x = pop_front(&head);
      int y = pop_front(&head);
      push_front(&head, x + y);
    }
    if (str == '-') {
      error2(&head);
      int x = pop_front(&head);
      int y = pop_front(&head);
      push_front(&head, x - y);
    }
    if (str == '*') {
      error2(&head);
      int x = pop_front(&head);
      int y = pop_front(&head);
      push_front(&head, x * y);
    }
    if (str == '/') {
      error2(&head);
      int x = pop_front(&head);
      int y = pop_front(&head);
      push_front(&head, x / y);
    }
    if (str == '%') {
      error2(&head);
      int x = pop_front(&head);
      int y = pop_front(&head);
      push_front(&head, x % y);
    }
  }
  
  if (error1(&head) == 0 || error2(&head) != 0) {
    printf("empty");
    printf("\n");
    exit(0);
  }

  printf("%d", pop_front(&head));
  return 0;
}
