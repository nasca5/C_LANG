#include "CQ.h"

void CQ_CreateQueue(CQ** Queue, int Capacity)
{
  // 큐를 자유 저장소(힙)에 생성
  *Queue = (CQ*)malloc(sizeof(CQ));

  // 입력된 Capacity + 1 만큼의 노드를 자유 저장소(힙)에 생성
  (*Queue)->Capacity = Capacity;

  (*Queue)->Array = (Node*)malloc((Capacity + 1) * sizeof(Node));
  (*Queue)->Front = 0;
  (*Queue)->Rear = 0;
}

void CQ_DestroyQueue(CQ* Queue)
{
  free(Queue->Array);
  free(Queue);
}

void CQ_EnQueue(CQ* Queue, ElementType Data)
{
  int Position = 0;

  if (Queue->Rear == Queue->Capacity)
  {
    Position = Queue->Rear;
    Queue->Rear = 0;
  }

  else
  {
    Position = Queue->Rear++;
  }

  Queue->Array[Position].Data = Data;
}

ElementType CQ_Dequeue(CQ* Queue)
{
  int Position = Queue->Front;

  if (Queue->Front == Queue->Capacity)
  {
    Queue->Front = 0;
  }

  else
  {
    Queue->Front++;
  }

  return Queue->Array[Position].Data;
}

int CQ_IsEmpty(CQ* Queue)
{
  return (Queue->Front == Queue->Rear);
}

int CQ_IsFull(CQ* Queue)
{
  if (Queue->Front < Queue->Rear)
  {
    return ((Queue->Rear - Queue->Front) == Queue->Capacity);
  }

  else
  {
    return ((Queue->Rear + 1) == Queue->Front);
  }
}

int CQ_GetSize(CQ* Queue)
{
  if (Queue->Front < Queue->Rear)
  {
    return (Queue->Rear - Queue->Front);
  }

  else
  {
    return (Queue->Rear + 1 + Queue->Capacity - Queue->Front);
  }
}


int main()
{
  int i;
  CQ* Queue = NULL;

  CQ_CreateQueue(&Queue, 10);

  CQ_EnQueue(Queue, 1);
  CQ_EnQueue(Queue, 2);
  CQ_EnQueue(Queue, 3);
  CQ_EnQueue(Queue, 4);

  for (i = 0; i < 3; i++)
  {
    printf("Dequeue: %d, ", CQ_Dequeue(Queue));
    printf("Front: %d, Rear: %d\n", Queue->Front, Queue->Rear);
  }

  i = 100;
  while(!CQ_IsFull(Queue))
  {
    CQ_EnQueue(Queue, i++);
  }

  printf("Capacity: %d, Size: %d\n", Queue->Capacity, CQ_GetSize(Queue));

  while(!CQ_IsEmpty(Queue))
  {
    printf("Dequeue: %d, ", CQ_Dequeue(Queue));
    printf("Front: %d, Rear: %d\n", Queue->Front, Queue->Rear);
  }

  CQ_DestroyQueue(Queue);

  return 0;
}
