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

    printf("�¾ ���� : %d", YEAR);

    int add = 3 + 7;

    printf("3 + 7 = %d\n", add);
    printf("%d x %d = %d\n", 30, 79, 30 * 79);

    int input;

    printf("���� �Է��ϼ��� : ");
    scanf_s("%d", &input);
    printf("�Է°� : %d\n", input);

    int one, two, three;

    printf("3���� ������ �Է��ϼ��� : ");

    scanf_s("%d%d%d", &one, &two, &three);

    printf("ù ��° �� : %d\n", one);
    printf("�� ��° �� : %d\n", two);
    printf("�� ��° �� : %d\n", three);

    char c = 'A';

    printf("%c\n", c);

    char str[256];

    printf("���ڿ��� �Է��ϼ��� : ");
    scanf_s("%s", str, sizeof(str));
    printf("%s\n", str);*/

    //������Ʈ
    //�������� �������� ������ �Լ� (���� �Լ�)
    //�̸�? ����? ������? Ű? ���˸�?
    //���� ���� ��·�
    char name[256];
    int age;
    double weight;
    double height;
    char crime[256];

    printf("�̸��� �����ΰ���?\n");

    scanf_s("%s", name, sizeof(name));

    printf("���̰� �� ���ΰ���?\n");

    scanf_s("%d", &age);

    printf("�����Ը� �����ּ���.\n");

    scanf_s("%lf", &weight);

    printf("Ű�� �����ּ���.\n");

    scanf_s("%lf", &height);

    printf("���� ���˸� �������̳���?\n");

    scanf_s("%s", crime, sizeof(crime));

    printf("\n\n---���� ����---\n\n");
    printf(" �̸�         : %s\n", name);      
    printf(" ����         : %d\n", age);
    printf(" ������       : %.2lf\n", weight);
    printf(" Ű           : %.2lf\n", height);
    printf(" ���� ����    : %s\n", crime);

    return 0;

}