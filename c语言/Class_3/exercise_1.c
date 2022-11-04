#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ipv4Eval.h"
#include "Ipv6Eval.h"

char q[50];

int main()
{
    int x;
    printf("请输入测试用例的个数：\n");
    scanf("%d", &x);
    gets(q);
    while (x--)
    {
        gets(q);
        if (ipv4Eval(q))
        {
            printf("Ipv4\n");
        }
        else if (ipv6Eval(q))
        {
            printf("IPv6\n");
        }
        else
        {
            printf("Neither\n");
        }
    }
    return 0;
}