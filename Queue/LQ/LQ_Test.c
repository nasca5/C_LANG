#include "LQ.h"

int LQ_IsEmpty(LQ* Queue)
{
  return (Queue->Front == NULL);
}
void LQ_CreateQueue(LQ** Queue)
{
  // 큐를 자유 저장소(힙)에 생성
  *Queue = (LQ*)malloc(sizeof(LQ));

  (*Queue)->Front = NULL;
  (*Queue)->Rear = NULL;
  (*Queue)->Count = 0;
}


Node* LQ_CreateNode(const char* Data)
{
  Node* NewNode = (Node*)malloc(sizeof(Node));
  NewNode->Data = (char*)malloc(strlen(Data) + 1);

  strcpy(NewNode->Data, Data);
  NewNode->NextNode = NULL;

  return NewNode;
}

void LQ_DestroyNode(Node* Node)
{
  free(Node->Data);
  free(Node);
}

void LQ_Enqueue(LQ* Queue, Node* NewNode)
{
  if (LQ_IsEmpty(Queue))
  {
    Queue->Front = NewNode;
    Queue->Rear = NewNode;
    Queue->Count++;
  }

  else
  {
    Queue->Rear->NextNode = NewNode;
    Queue->Rear = NewNode;
    Queue->Count++;
  }
}

Node* LQ_Dequeue(LQ* Queue)
{
  Node* Popped = NULL;

  if (!LQ_IsEmpty(Queue)) 
  {
    Popped = Queue->Front;
    Queue->Front = Popped->NextNode;
    Queue->Count--;
  }

  return Popped;
}


int LQ_GetSize(LQ* Queue)
{
  return Queue->Count;
}

void LQ_DestroyQueue(LQ* Queue)
{
  // 자유 저장소(힙)에 생성한 메모리 공간을 지움
  while(!LQ_IsEmpty(Queue))
  {
    Node* Popped = LQ_Dequeue(Queue);
    LQ_DestroyNode(Popped);
  }

  free(Queue);
}
int main() 
{
  LQ* Queue = NULL;
  Node* Popped;

  LQ_CreateQueue(&Queue);

  LQ_Enqueue(Queue, LQ_CreateNode("abc"));
  LQ_Enqueue(Queue, LQ_CreateNode("def"));
  LQ_Enqueue(Queue, LQ_CreateNode("efg"));
  LQ_Enqueue(Queue, LQ_CreateNode("hij"));
  
  printf("Queue Size : %d\n", LQ_GetSize(Queue));

  while(!LQ_IsEmpty(Queue))
  {
    Popped = LQ_Dequeue(Queue);
    
    printf("Dequeue : %s\n", Popped->Data);
    LQ_DestroyNode(Popped);
  }

  LQ_DestroyQueue(Queue);

  return 0;
}
