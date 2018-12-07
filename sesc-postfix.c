#include <stdio.h>
#include <stdlib.h>
#include "postfix.h"

//int error1(Node *head){
  //if (head==NULL) {
   // printf("empty");
 //   printf("\n");      
 // }
//}

//int error2(Node *head){
//Node *hea = head->next;
 // if (hea==NULL) {
 //   printf("empty");
 //   printf("\n");     
//  }
//}

int main(void) {
  Node *head= NULL;
  char str;
  scanf("%c", &str);
  while(scanf("%c", &str) && str != '\n'){
    scanf("%c", &str);
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
