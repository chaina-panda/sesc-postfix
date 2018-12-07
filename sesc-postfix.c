#include <stdio.h>
#include <stdlib.h>
#include "postfix.h"
int main(void) {
  Node *head= NULL;
  char str;
  while(scanf("%c", &str) && str != '\n'){
    if (str <= '9' && str >= '0')
      push_front(&head, str);
    if (str == '~') {    
      int x = -(pop_front(&head));
      push_front(&head, x);
    }
    if (str == '+') {     
      int x = pop_front(&head);
      int y = pop_front(&head);
      push_front(&head, x + y);
    }
    if (str == '-') {
      int x = pop_front(&head);
      int y = pop_front(&head);
      push_front(&head, x - y);
    }
    if (str == '*') {
      int x = pop_front(&head);
      int y = pop_front(&head);
      push_front(&head, x * y);
    }
    if (str == '/') {
      int x = pop_front(&head);
      int y = pop_front(&head);
      push_front(&head, x / y);
    }
    if (str == '%') {
      int x = pop_front(&head);
      int y = pop_front(&head);
      push_front(&head, x % y);
    }
  }
  printf("%d", pop_front(&head));
  return 0;
}
