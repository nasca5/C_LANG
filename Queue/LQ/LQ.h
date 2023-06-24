#ifndef TEST
#define TEST

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tagNode
{
  char* Data;
  struct tagNode* NextNode;
} Node;

typedef struct LinkedQueue
{
  Node* Front;
  Node* Rear;
  int Count;
} LQ;

#endif
