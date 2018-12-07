#include <stdio.h>
#include <stdlib.h>
#include "postfix.h"
int main(void) {
  Node *head= NULL;
  char str;
  scanf("%c", &str);
  for( ;str != '\n'; ){
    if (str <= '9' && str >= '0'){
      push_front(&head, str - 48);
    }
    switch (str){
    case '~':   
      {int x = -(pop_front(&head));
      push_front(&head, x);
      break;}
    case '+':     
      {int x = pop_front(&head);
      int y = pop_front(&head);
      push_front(&head, x + y);
      break;}
    case '-':
      {int x = pop_front(&head);
      int y = pop_front(&head);
      push_front(&head, x - y);
      break;}
    case '*':
      {int x = pop_front(&head);
      int y = pop_front(&head);
      push_front(&head, x * y);
      break;}
    case '/':
      {int x = pop_front(&head);
      int y = pop_front(&head);
      push_front(&head, x / y);
      break;}
    case '%':
      {int x = pop_front(&head);
      int y = pop_front(&head);
      push_front(&head, x % y);
      break;}
    }
    scanf("%c", &str);
  }
  printf("%d", pop_front(&head));
  return 0;
}
