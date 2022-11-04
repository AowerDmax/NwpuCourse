// 以邻接数组形式

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *arr;
int **p;
int x, t;
char **str;

int find(char *val)
{
    for (int i = 0; i < x; i++)
    {
        if (!strcmp(str[i], val))
        {
            return i;
        }
    }
    return 0;
}

void dfs(int u)
{
    arr[u] = 1;
    printf("%s ", str[u]);
    for (int i = 0; i < x; i++)
        if (!arr[i] && p[u][i])
            dfs(i);
}

void bfs()
{
    int top, tail;
    int *queue = (int *)malloc(sizeof(int) * t);
    queue[0] = 0;
    top = 0;
    tail = 0;
    while (top <= tail)
    {
        int idx = queue[top];
        if (!arr[idx])
        {
            arr[idx] = 1;
            for (int i = 0; i < x; i++)
            {
                if (p[idx][i])
                    queue[++tail] = i;
            }
            printf("%s ", str[idx]);
        }
        top++;
    }
}

int main()
{
    printf("请输入顶点数:");
    scanf("%d", &x);
    p = (int **)malloc(sizeof(int *) * x);
    str = (char **)malloc(sizeof(char *) * x);
    for (int i = 0; i < x; i++)
    {
        p[i] = (int *)malloc(sizeof(int) * x);
        str[i] = (char *)malloc(sizeof(char) * 20);
        memset(p[i], 0, sizeof(int) * x);
    }
    arr = (int *)malloc(sizeof(int) * x);

    printf("请输入顶点: ");
    for (int i = 0; i < x; i++)
        scanf("%s", str[i]);

    printf("请输入边数: ");
    scanf("%d", &t);
    printf("请输入边: \n");
    for (int i = 0; i < t; i++)
    {
        char names[20];
        int a, b;
        scanf("%s", names);
        a = find(names);
        scanf("%s", names);
        b = find(names);
        p[a][b] = 1;
        p[b][a] = 1;
    }

    // for (int i = 0; i < x; i++)
    // {
    //     for (int j = 0; j < x; j++)
    //         printf("%d ", p[i][j]);
    //     printf("\n");
    // }

    memset(arr, 0, sizeof(int) * x);
    printf("广度优先搜索的结果为: ");
    bfs();

    memset(arr, 0, sizeof(int) * x);
    printf("\n深度优先搜索的结果为: ");
    dfs(0);
    return 0;
}