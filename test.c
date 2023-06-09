#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char str[100];
  int arr[100] = {0};
  int i = 1;
  int size = 1;
  // printf("string : ");
  // scanf("%s", str);

  // while(str[i] != '\0') {
  //   arr[i + 1] = str[i] - 48;
  //   i++;
  // }

  // for(int i = 0; i < (strlen(str) + 1); i++) {
  //   printf("%d", arr[i]);
  // }

  printf("number : ");
  while(scanf("%1d", &arr[i]) == 1) {
    i++;
    size++;
  } 

  for(int i = 0; i < size; i++) {
    printf("%d\n", arr[i]);
  }
  return 0;
}