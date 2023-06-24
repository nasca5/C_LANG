#include <iostream>
#include <string.h>

// N차원 배열을 생성하는 class
class Array
{
private:
  const int dim; // 몇 차원 배열인지
  int *size;     // size[0] * size[1] * size[2] ... size[dim - 1] 크기의 배열

  // class 안에는 구조체뿐만 아니라 다른 class도 넣을 수 있다.
  // 따라서 구조체의 정의 자체를 Array class 안에 넣어놨다.
  // 구조체의 정의 자체를 class 안에 넣어놓은 이유는 Array class의 인스턴스가 내부적으로 어떻게 작동
  // 하는지 공개하고 싶지 않고, 또 내부 정보에 접근하는 것을 원치 않기 때문이다.
  // C++ 구조체는 모든 멤버 함수, 변수가 디폴트로 public인 class라고 생각하면 된다.
  typedef struct Address
  {
    int level;
    void *next;
  } Addr;

  Addr *Top;

public:
  Array(int dim, int *array_size) : dim(dim)
  {
    size = new int[dim];
    for (int i = 0; i < dim; i++)
    {
      size[i] = array_size[i];
    }

    Top = new Addr;
    Top->level = 0;

    InitAddr(Top);
  }

  Array(const Array &arr) : dim(arr.dim)
  {
    size = new int[dim];
    for (int i = 0; i < dim; i++)
    {
      size[i] = arr.size[i];
    }

    Top = new Addr;
    Top->level = 0;

    InitAddr(Top);

    // 배열의 내용 복사
    CopyAddr(Top, arr.Top);
  }

  // 소멸자 호출
  // Top 뿐만이 아니라 size에 대해서도 해제를 해주어야 한다. 
  // 모든 동적으로 할당된 메모리에 대해서 해제하는 것을 잊지 말자.
  ~Array()
  {
    DelAddr(Top);
    delete[] size;
  }

  void InitAddr(Addr *Current);
  void DelAddr(Addr *Del);
  void CopyAddr(Addr *dst, Addr *src);
};

// 임의의 N 차원 배열을 생성하기 위해서 재귀 함수를 이용할 수 있다.
// 재귀 함수를 이용할 때는 다음의 두 가지 과정을 머리에 새기고 있으면 된다.
// 1. 함수에서 처리하는 것, 즉 현재 단계에서 다음 단계로 넘어가는 과정은 무엇인가?
// 2. 재귀 함수의 호출이 종료되는 조건은 무엇인가?

// 1. 함수에서 처리하는 것, 즉 현재 단계에서 다음 단계로 넘어가는 과정은 무엇인가?
// -> 현재 n 레벨의 Addr 배열이라면, 이 배열들의 next에는 다음 레벨인 n + 1 레벨의 Addr 배열들의 시작 주소
//    를 각각 할당해주고, 이 각각의 배열들에 대해 다시 재귀 함수를 호출해주는 식으로 처리하면 된다.
// 2. 재귀 함수의 호출이 종료되는 조건은 무엇인가?
// -> 재귀 함수 호출이 종료되기 위한 조건은 현재 처리하고 있는 Addr 배열의 레벨이 (dim -1)이 되는 것이다.
// -> Addr 배열의 레벨이 (dim - 1)이면, 이 배열의 원소들((dim - 1) 레벨을 가진 Addr 배열들)의 next에는
//    int 배열의 시작 주소를 할당해주고 재귀 호출이 끝나게 된다.

// 이러한 방식으로 함수를 재귀 호출하는 것은 '깊이 우선 탐색'을 하는 것과 동일하다.
void Array::InitAddr(Addr *Current)
{
  // Current가 NULL일 때를 대비한 예외 처리 구문
  if (!Current)
    return;

  // 재귀 함수 종료 조건
  if (Current->level == dim - 1)
  {
    Current->next = new int[size[Current->level]];
    memset(Current->next, 0, sizeof(int) * size[Current->level]);
  }

  // 현재 Addr 구조체 배열들의 next에 각각 다음 Addr 구조체 배열의 시작 주소를 할당
  // 이때 다음 Addr 구조체 배열들의 레벨은 현재 Addr 구조체 배열들의 레벨 + 1 이다.
  Current->next = new Addr[size[Current->level]];

  for (int i = 0; i < size[Current->level]; i++)
  {
    (static_cast<Addr *>(Current->next))[i].level = Current->level + 1;

    InitAddr(&(static_cast<Addr *>(Current->next))[i]);
  }
}

// 생성자를 만들었으므로, 소멸자도 비슷한 방식으로 만들면 된다.
// 이때 주의할 점은 생성자는 위에서 아래로 메모리를 할당했지만
// 소멸자는 아래에서 위로 메모리를 해제해나가야 한다는 점이다.
// 만약 위의 메모리부터 해제한다면, 다음 메모리를 해제하려 할 때 이미 해제된 메모리에
// 접근하려 하는 것과 같으므로 잘못된 방식이라고 할 수 있다.
void Array::DelAddr(Addr *Current)
{
  if (!Current)
    return;

  for (int i = 0; Current->level < dim - 1 && i < size[Current->level]; i++)
  {
    DelAddr(&static_cast<Addr *>(Current->next)[i]);
  }

  if (Current->level == dim - 1)
  {
    delete[] static_cast<int *>(Current->next);
  }

  delete[] static_cast<Addr *>(Current->next);
}

// 재귀 함수 형식으로 생성자를 통해 인자인 Array 인스턴스의 내용을 복사함
void Array::CopyAddr(Addr *dst, Addr *src)
{
  if (dst->level == dim - 1)
  {
    for (int i = 0; i < size[dst->level]; i++)
    {
      static_cast<int *>(dst->next)[i] = static_cast<int *>(src->next)[i];
    }
    return;
  }

  for (int i = 0; i < size[dst->level]; i++)
  {
    CopyAddr(&static_cast<Addr *>(dst->next)[i], &static_cast<Addr *>(src->next)[i]);
  }
}

int main()
{
  return 0;
}
