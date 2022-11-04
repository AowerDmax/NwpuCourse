//用函数编程实现杨辉三角
#include <stdio.h>
#include <stdlib.h>

typedef long long ll;
int main()
{
    //用二级指针动态申请二维数组
    ll **q;
    //定义输入的数
    int x;
    scanf("%d", &x);
    //初始化二维数组
    q = (ll **)malloc(sizeof(ll *) * x);
    for (int i = 0; i < x; i++)
        q[i] = (ll *)malloc(sizeof(ll) * x);
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            q[i][j] = 0;
        }
    }
    //输出第一行
    q[0][0] = 1;
    printf("%lld\n", q[0][0]);
    for (int i = 1; i < x; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            // 如果是第0列就为1， 不是就是q[i - 1][j - 1] + q[i - 1][j];
            q[i][j] = j == 0 ? 1 : q[i - 1][j - 1] + q[i - 1][j];
            printf("%lld ", q[i][j]);
        }
        printf("\n");
    }
    //释放内存
    for (int i = 0; i < x; i++)
        free(q[i]);
    free(q);

    return 0;
}
