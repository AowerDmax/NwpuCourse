// 练习2 挑战大数存储问题 40的阶乘
#include <stdio.h>
#include <string.h>
#define N 1000 + 10
// C存放大数，0放置个位， 1放置十位
int C[N], k, len;
// 计算 一个超过int范围数 与 一个在int范围的数 相乘
void mul(int A[], int b)
{
    // t记录当前位与b相乘得到的值
    int t = 0, i;
    //记录当前处理的位
    k = -1;
    for (i = 0; i <= len || t; i++)
    {
        // 如果i <= len 说明大数还没有处理完，计算当前位和b相乘的数
        if (i <= len)
            t += A[i] * b;
        //余数
        C[++k] = t % 10;
        //进位
        t /= 10;
        // printf("k:%d\n", k);
        //如果 t != 0 && i > len 说明大数处理完了，但是进位没有处理完
    }
    len = k;
    // printf("len : %d\n", len);
}
int main()
{
    //初始化C数组
    memset(C, 0, sizeof(C));
    //记录数组使用的长度为0
    len = 0;
    //将数组C的第0个值初始化为1
    C[0] = 1;
    for (int i = 1; i <= 40; i++)
    {
        mul(C, i);
        printf("第%d个数的阶乘为:", i);
        //从第k位(最高位输出)一直输出到最低位0
        for (int j = k; j >= 0; j--)
            printf("%d", C[j]);
        printf("\n");
    }
    return 0;
}