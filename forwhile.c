#include <stdio.h>

int main() {
    
    //++
    /*int a = 10;
    printf("a�� %d", a);

    a++

    printf("a�� %d", a);*/

    /*int b = 20;

    printf("b�� %d\n", ++b);
    printf("b�� %d\n", b++);
    printf("b�� %d\n", b);*/

    /*int i = 1;
    printf("hello world%d\n", i++);
    printf("hello world%d\n", i++);
    printf("hello world%d\n", i++);
    printf("hello world%d\n", i++);
    printf("hello world%d\n", i++);
    printf("hello world%d\n", i++);
    printf("hello world%d\n", i++);
    printf("hello world%d\n", i++);
    printf("hello world%d\n", i++);
    printf("hello world%d\n", i++);*/
    
    //for��
    /*for (int i = 1; i <= 10; i++) {
        printf("hello world%d\n", i);
    }*/

    //while��
    /*int i = 1;
    while (i <= 10)
    {
        printf("hello world%d\n", i);
        i++;
    }*/

    //do while��
    /*int i = 1;
    do
    {
        printf("hello world%d\n", i);
        i++;
    } while (i <= 10);*/

    //2�� �ݺ���
    /*for (int i = 1; i <= 3; i++)
    {
        printf("ù ��° �ݺ��� : %d\n", i);

        for (int j = 1; j <= 5; j++)
        {
            printf("   �� ��° �ݺ��� : %d\n", j);
        }
        
    }*/
    
    //������
    /*printf("\n\n--- ������ --- \n\n");
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
        printf("%d x %d = %d\n", i, j, i*j);
        }
        
    }*/

    //���� �ݺ��� ����ġ��
    /*for (int i = 1; i <= 5; i++)
    {
        
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }

        printf("\n");
        
    }*/

    /*for (int i = 0; i < 5; i++)
    {
        
        for (int j = 4; j > i; j--)
        
        {
            printf(" ");
        }

        for (int r = 0; r <= i; r++)
        {
            printf("*");
        }
        
        printf("\n");
        
    }*/
    
    //������Ʈ
    //�Ƕ�̵� �ױ�
    int floor;

    printf("�� ������ �����ðڽ��ϱ�? : ");
    scanf_s("%d", &floor);

    for (int i = 1; i <= floor; i++)
    {
        for (int j = 0; j < (floor - i); j++)
        {
            printf(" ");
        }
        for (int k = 0; k < (2*i-1); k++)
        {
            printf("*");
        }
    printf("\n");
    }

    return 0;

}