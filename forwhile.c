#include <stdio.h>

int main() {
    
    //++
    /*int a = 10;
    printf("a는 %d", a);

    a++

    printf("a는 %d", a);*/

    /*int b = 20;

    printf("b는 %d\n", ++b);
    printf("b는 %d\n", b++);
    printf("b는 %d\n", b);*/

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
    
    //for문
    /*for (int i = 1; i <= 10; i++) {
        printf("hello world%d\n", i);
    }*/

    //while문
    /*int i = 1;
    while (i <= 10)
    {
        printf("hello world%d\n", i);
        i++;
    }*/

    //do while문
    /*int i = 1;
    do
    {
        printf("hello world%d\n", i);
        i++;
    } while (i <= 10);*/

    //2중 반복문
    /*for (int i = 1; i <= 3; i++)
    {
        printf("첫 번째 반복문 : %d\n", i);

        for (int j = 1; j <= 5; j++)
        {
            printf("   두 번째 반복문 : %d\n", j);
        }
        
    }*/
    
    //구구단
    /*printf("\n\n--- 구구단 --- \n\n");
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
        printf("%d x %d = %d\n", i, j, i*j);
        }
        
    }*/

    //이중 반복문 파헤치기
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
    
    //프로젝트
    //피라미드 쌓기
    int floor;

    printf("몇 층으로 쌓으시겠습니까? : ");
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