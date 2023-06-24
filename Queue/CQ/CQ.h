#ifndef TEST
#define TEST

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElementType;

typedef struct TagNode
{
  ElementType Data;
} Node;

typedef struct {
  int Capacity;
  int Front;
  int Rear;
  Node* Array;
} CQ;

void CQ_CreateQueue(CQ** Queue, int Capacity);
void CQ_DestroyQueue(CQ* Queue);
void CQ_EnQueue(CQ* Queue, ElementType Data);
ElementType CQ_Dequeue(CQ* Queue);
int CQ_IsEmpty(CQ* Queue);
int CQ_IsFull(CQ* Queue);
int CQ_GetSize(CQ* Queue);

#endif
