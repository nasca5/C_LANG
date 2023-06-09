#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct TagNode
{
  ElementType data;         // data
  struct TagNode *NextNode; // next node
} Node;

// SLL : abbreviation of Singly Linked List
// DLL : abbreviation of Double Linked List

// Create NewNode
Node *SLL_CreateNode(ElementType NewData)
{
  Node *NewNode = (Node *)malloc(sizeof(Node)); // assign memory being about Node struct size

  NewNode->data = NewData;  // assign NewData to data of NewNode
  NewNode->NextNode = NULL; // NextNode isn't decide yet

  return NewNode; // return Address of NewNode
}

// Destroy Node
void SLL_DestroyNode(Node *Node)
{
  free(Node);
}

void SLL_AppendNode(Node **Head, Node *NewNode)
{
  if ((*Head) == NULL)
  {
    *Head = NewNode;
  }

  else
  {
    Node *Tail = (*Head);
    while (Tail->NextNode != NULL)
    {
      Tail = Tail->NextNode;
    }

    Tail->NextNode = NewNode;
  }
}

Node *SLL_GetNodeAt(Node *Head, int Location)
{

  Node *Current = Head;

  while (Current != NULL && (--Location) >= 0)
  {
    Current = Current->NextNode;
  }

  return Current;
}

void SLL_RemoveNode(Node **Head, Node *Remove)
{
  if (*Head == Remove)
  {
    *Head = Remove->NextNode;
  }
  else
  {
    Node *Tail = *Head;
    while (Tail != NULL && Tail->NextNode != Remove)
    {
      Tail = Tail->NextNode;
    }
    if (Tail != NULL)
    {
      Tail->NextNode = Remove->NextNode;
    }
  }
}

int main()
{
  Node *List = NULL;
  Node *MyNode = NULL;

  SLL_AppendNode(&List, SLL_CreateNode(1));
  SLL_AppendNode(&List, SLL_CreateNode(2));
  SLL_AppendNode(&List, SLL_CreateNode(3));

  MyNode = SLL_GetNodeAt(List, 1);
  printf("%d", MyNode->data);

  SLL_RemoveNode(&List, MyNode);
  SLL_DestroyNode(MyNode);

  return 0;
}
