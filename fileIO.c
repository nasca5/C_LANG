#include <stdio.h>

typedef struct
{
  int id;
  char name[20];
  int score;
} Student;

int main()
{
  FILE *fp;
  const char *file_name = "test.txt";
  Student student;

  fp = fopen(file_name, "a+b");

  printf("input\n");
  while (scanf("%d / %s / %d", &student.id, student.name, &student.score) == 3)
  {
    fwrite(&student, sizeof(Student), 1, fp);
  }

  fseek(fp, (long int)sizeof(Student) * -1, SEEK_CUR);

  while (fread(&student, sizeof(Student), 1, fp) == 1)
  {
    printf("%d / %s / %d", student.id, student.name, student.score);
  }

  fp = freopen(file_name, "r+b", fp);
  // 점수 수정

  printf("\ninput score : ");
  scanf("%d", &student.score);

  fwrite(&student, sizeof(Student), 1, fp);

  fseek(fp, (long int)sizeof(Student) * -1, SEEK_CUR);
  while (fread(&student, sizeof(Student), 1, fp) == 1)
  {
    printf("%d / %s / %d", student.id, student.name, student.score);
  }

  return 0;
}
