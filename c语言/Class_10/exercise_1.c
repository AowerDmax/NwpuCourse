#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int **d;
int *value;
int n, m, a, b, x;

/**
 * 使用动态规划的思想
 * 定义函数 f[k][i][j] 代表从i出发到只能通过前k个节点到j的最短距离
 * f[0][i][j] 代表不经过任何点，从i直接到j的距离
 * f[1][i][j] 是 (不经过任何点，从i直接到j的距离) 和 (从i到1， 再从1到j距离之和) 两者中的最小值 即 f[1][i][j] = min(f[0][i][j], f[0][i][1] + f[0][1][j])
 * f[2][i][j] 是 (不经过任何点，从i直接到j的距离) 和 (经过点 1) 和 (经过 点 2) 和 (经过 点 1 点2) (经过 点2 点1)五者中的最小值
 * 假设k从小到大依次计算
 * f[2][i][j] 可以分为 经过点2， 和不经过点2的情况
 * 不经过点2(只能经过2之前的节点)  即：这种情况为 f[1][i][j]
 * 经过点2：(一定经过节点2)  即：这种情况为 f[1][i][2] + f[1][2][j]
 * f[k][i][j] 分两种情况获得
 * 1. 不经过节点k， 可以经过节点k之前的任意节点，即f[k - 1][i][j]
 * 2. 经过节点k， 节点k之前的任意节点也可以随意经过， 即f[k - 1][i][k] + f[k - 1][k][j]
 * 递推获得
 * f[k][i][j] = min(f[k - 1][i][j], f[k - 1][i][k] + f[k - 1][k][j])
 * 因为最后要求的是经过n个节点，且经过前k个节点的结果在最后是没有意义的，
 * 因为k从小到大计算，会覆盖
 * 所以式子可以优化为:
 * f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
 */
void floyed()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main()
{
    scanf("%d %d", &n, &m);
    d = (int **)malloc(sizeof(int *) * (n + 1));
    value = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 1; i <= n; i++)
    {
        d[i] = (int *)malloc(sizeof(int) * (n + 1));
        memset(d[i], 0x3f, sizeof(int) * (n + 1));
        d[i][i] = 0;
        scanf("%d", &value[i]);
    }

    while (m--)
    {
        scanf("%d %d %d", &a, &b, &x);
        d[a][b] = x;
        d[b][a] = x;
    }
    floyed();

    for (int i = 1; i <= n; i++)
    {
        int minValue = 1e9;
        for (int j = 1; j <= n; j++)
            minValue = min(minValue, d[i][j] + value[j]);
        printf("%d ", minValue);
    }

    return 0;
}