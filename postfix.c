#include <stdio.h>
#include <stdlib.h>
#include "postfix.h"

void push_front(Node **head, int num) {
  Node *key = (Node*) malloc(sizeof(Node));
  key->value = num;
  key->next = (*head);
  (*head) = key;
}

int pop_front(Node **head) {
  int value = (*head)->value;
  Node *ear = NULL; 
  ear = (*head);
  (*head) = (*head)->next;
  free(ear);
  return value;
}

int size(Node *head){
  int i = 0;
  for(i; head; i++ ){
    head = head->next;
  }
  return i;
}