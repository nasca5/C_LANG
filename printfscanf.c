#include <stdio.h>

int main() {

    /*int age;

    printf("%d\n", age);

    age = 13;
    
    printf("%d\n", age);            
    
    float f = 46.5f;
    printf("%.2f\n", f);

    double d = 4.428;

    printf("%.2lf\n", d);

    const int YEAR = 2000;

    printf("태어난 연도 : %d", YEAR);

    int add = 3 + 7;

    printf("3 + 7 = %d\n", add);
    printf("%d x %d = %d\n", 30, 79, 30 * 79);

    int input;

    printf("값을 입력하세요 : ");
    scanf_s("%d", &input);
    printf("입력값 : %d\n", input);

    int one, two, three;

    printf("3개의 정수를 입력하세요 : ");

    scanf_s("%d%d%d", &one, &two, &three);

    printf("첫 번째 값 : %d\n", one);
    printf("두 번째 값 : %d\n", two);
    printf("세 번째 값 : %d\n", three);

    char c = 'A';

    printf("%c\n", c);

    char str[256];

    printf("문자열을 입력하세요 : ");
    scanf_s("%s", str, sizeof(str));
    printf("%s\n", str);*/

    //프로젝트
    //경찰관이 범죄자의 정보를 입수 (정보 입수)
    //이름? 나이? 몸무게? 키? 범죄명?
    //조서 내용 출력력
    char name[256];
    int age;
    double weight;
    double height;
    char crime[256];

    printf("이름이 무엇인가요?\n");

    scanf_s("%s", name, sizeof(name));

    printf("나이가 몇 살인가요?\n");

    scanf_s("%d", &age);

    printf("몸무게를 적어주세요.\n");

    scanf_s("%lf", &weight);

    printf("키를 적어주세요.\n");

    scanf_s("%lf", &height);

    printf("무슨 범죄를 저지르셨나요?\n");

    scanf_s("%s", crime, sizeof(crime));

    printf("\n\n---조서 내용---\n\n");
    printf(" 이름         : %s\n", name);      
    printf(" 나이         : %d\n", age);
    printf(" 몸무게       : %.2lf\n", weight);
    printf(" 키           : %.2lf\n", height);
    printf(" 범죄 내용    : %s\n", crime);

    return 0;

}