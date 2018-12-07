#pragma once

typedef struct Node {
  int value;
  struct Node *next;
} Node;

void push_front(Node **head, int num);
int pop_front(Node **head);
