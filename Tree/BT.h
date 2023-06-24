#ifndef TEST
#define TEST

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct tagLCRSNode
{
  struct tagLCRSNode* LC;
  struct tagLCRSNode* RS;
  ElementType Data;
} LCRS;

#endif
