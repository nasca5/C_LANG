#include "BT.h"

LCRS *LCRS_CreateNode(ElementType NewData)
{
  LCRS *NewNode = (LCRS *)malloc(sizeof(LCRS));
  NewNode->Data = NewData;
  NewNode->LC = NULL;
  NewNode->RS = NULL;

  return NewNode;
}

void LCRS_DestroyNode(LCRS *Remove)
{
  free(Remove);
}

void LCRS_DestroyTree(LCRS *Root)
{
  if (Root->RS != NULL)
  {
    LCRS_DestroyTree(Root->RS);
  }

  if (Root->LC != NULL)
  {
    LCRS_DestroyTree(Root->LC);
  }

  LCRS_DestroyNode(Root);
}

void LCRS_AddChildNode(LCRS *Parent, LCRS *Child)
{
  if (Parent->LC == NULL)
  {
    Parent->LC = Child;
  }

  else
  {
    LCRS *temp = Parent->LC;
    while (temp->RS != NULL)
    {
      temp = temp->RS;
    }
    temp->RS = Child;
  }
}

void LCRS_PrintTree(LCRS *Node, int Depth)
{
  int i;
  for (i = 0; i < Depth - 1; i++)
  {
    printf("   ");
  }

  if (Depth > 0)
  {
    printf("+--");
  }

  printf("%c\n", Node->Data);

  if (Node->LC != NULL)
  {
    LCRS_PrintTree(Node->LC, Depth + 1);
  }

  if (Node->RS != NULL)
  {
    LCRS_PrintTree(Node->RS, Depth);
  }
}

void PrintAllChild(LCRS *Child)
{
  LCRS *temp = Child;
  while (temp != NULL)
  {
    printf("%c  ", temp->Data);
    temp = temp->RS;
  }
}

void LCRS_PrintLevel(LCRS *Root, int Level)
{
  LCRS *temp = Root;
  if (Level == 0)
  {
    printf("%c  ", temp->Data);
  }

  else
  {
    while (Level - 1)
    {
      if (temp->LC != NULL)
      {
        temp = temp->LC;
      }

      else if (temp->RS != NULL)
      {
        temp = temp->RS;
      }

      Level--;
    }

    while (temp != NULL)
      {
        if (temp->LC != NULL)
        {
          PrintAllChild(temp->LC);
        }
        temp = temp->RS;
      }
  }
}

int main()
{
  LCRS *Root = LCRS_CreateNode('A');
  LCRS *B = LCRS_CreateNode('B');
  LCRS *C = LCRS_CreateNode('C');
  LCRS *D = LCRS_CreateNode('D');
  LCRS *E = LCRS_CreateNode('E');
  LCRS *F = LCRS_CreateNode('F');
  LCRS *G = LCRS_CreateNode('G');
  LCRS *H = LCRS_CreateNode('H');
  LCRS *I = LCRS_CreateNode('I');
  LCRS *J = LCRS_CreateNode('J');
  LCRS *K = LCRS_CreateNode('K');

  // 트리에 노드 추가
  LCRS_AddChildNode(Root, B);
  LCRS_AddChildNode(B, C);
  LCRS_AddChildNode(B, D);
  LCRS_AddChildNode(D, E);
  LCRS_AddChildNode(D, F);

  LCRS_AddChildNode(Root, G);
  LCRS_AddChildNode(G, H);

  LCRS_AddChildNode(Root, I);
  LCRS_AddChildNode(I, J);
  LCRS_AddChildNode(I, K);

  LCRS_PrintTree(Root, 0);
  LCRS_PrintLevel(Root, 3);

  LCRS_DestroyTree(Root);

  return 0;
}
