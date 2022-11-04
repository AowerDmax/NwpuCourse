#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m;
int h[1000], cnt;
int *arr;
char *buff;
int n, m;

void down(int u) //调整函数
{
    // t记录最小点的编号
    int t = u;
    //有左儿子，并且左儿子比t节点的值大，更新t
    if (u * 2 <= cnt && h[u * 2] > h[t])
        t = u * 2;

    //有右儿子，并且右儿子比t节点的值大，更新t
    if (u * 2 + 1 <= cnt && h[u * 2 + 1] > h[t])
        t = u * 2 + 1;

    if (u != t)
    {
        int num = h[u];
        h[u] = h[t];
        h[t] = num;
        down(t);
    }
}

int main()
{
    FILE *fp = NULL;
    buff = (char *)malloc(sizeof(char) * 255);
    fp = fopen("t1.txt", "r");
    FILE *out = fopen("out_t1.txt", "w");
    while (!feof(fp))
    {
        fscanf(fp, "%d", &n);
        fscanf(fp, "%d", &m);
        memset(h, 0, sizeof(int) * 1000);
        int res = 0;
        for (int i = 1; i <= m; i++)
        {
            fscanf(fp, "%d", &h[i]);
            cnt = i;
            for (int k = 1; k <= cnt; k++)
                res += h[k];
        }
        cnt = m;
        for (int i = m / 2; i; i--)
        {
            down(i);
        }
        for (int i = m + 1; i <= n; i++)
        {
            fscanf(fp, "%d", &h[i]);
            if (h[i] < h[1])
            {
                printf("第%d天: pop: %d\n", i, h[1]);
                fprintf(out, "第%d天: pop: %d\n", i, h[1]);
                h[1] = h[i];
                down(1);
            }
            else
            {
                printf("第%d天: pop: %d \n", i, h[i]);
                fprintf(out, "第%d天: pop: %d \n", i, h[i]);
            }
            for (int k = 1; k <= cnt; k++)
                res += h[k];
        }
        for (int i = n + 1; i <= n + m; i++)
        {
            printf("第%d天: pop: %d\n", i, h[1]);
            fprintf(out, "第%d天: pop: %d\n", i, h[1]);
            h[1] = h[cnt--]; //删除堆顶（用最后一个数覆盖第一个数） 并且长度 减1
            down(1);         //让覆盖好的数往下面走
            for (int k = 1; k <= cnt; k++)
                res += h[k];
        }
        printf("res : %d \n", res);
        fprintf(out, "res : %d \n", res);
    }
    return 0;
}