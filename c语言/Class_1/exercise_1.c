#include <stdio.h>
//返回 第 x 月 一共有几只兔子
int nums(int x)
{
    if (x == 1)
    {
        return 1;
    }
    if (x == 2)
    {
        return 2;
    }
    return nums(x - 1) + nums(x - 2);
}
int main()
{
    // 1 2 3 4 5 6 7 8 9 10 11 12
    //成兔 + 幼兔
    // 1+0 1+1 2+1 3+2 5+3 8+5 ....
    // f(n) = f (n - 1) + f(n - 2)
    int x;
    scanf("%d", &x);
    printf("%d个月后兔子的数量：%d", x, nums(x));
    return 0;
}