#include <stdio.h>

int main() {
  int a;
  int *p = &a;

  a = 2;

  printf("%d\n", a);

  *p = 3;

  printf("%d \n", a);

  int arr[3] = {1, 2, 3};
  printf("%d", arr[2]);

  // arr[2] = *(arr + 2)

  int* ptr;
  ptr = &arr[0];
  ptr = arr;


  printf("%d\n", *(ptr+2));

  printf("%p\n", *ptr);
  printf("%p\n", &arr[0]);



  char str[10] = "hello";

  char* ptrr;
  ptrr = str;

  printf("%c", *(ptrr+4));


  
  return 0;
}

// �������� ������ �����Ͱ� ����Ű�� ���� ũ�⸦ �������� ����Ѵ�.
// 