//用数组实现邻接表

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *arr, *head, *e, *ne;
int x, t;
int num = 0;
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

void add(int a, int b)
{
    e[num] = b;
    ne[num] = head[a];
    head[a] = num++;
}

void dfs(int u)
{
    arr[u] = 1;
    printf("%s ", str[u]);
    for (int i = head[u]; i != -1; i = ne[i])
    {
        int val = e[i];
        if (!arr[val])
            dfs(val);
    }
}

void bfs()
{
    int top, tail;
    int *queue = (int *)malloc(sizeof(int) * (x * x));
    queue[0] = 0;
    top = 0;
    tail = 0;
    while (top <= tail)
    {
        int idx = queue[top];
        if (!arr[idx])
        {
            arr[idx] = 1;
            for (int i = head[idx]; i != -1; i = ne[i])
                queue[++tail] = e[i];
            printf("%s ", str[idx]);
        }
        top++;
    }
}

int main()
{
    printf("请输入顶点数:");
    scanf("%d", &x);

    head = (int *)malloc(sizeof(int) * x);
    memset(head, -1, sizeof(int) * x);

    str = (char **)malloc(sizeof(char *) * x);
    for (int i = 0; i < x; i++)
        str[i] = (char *)malloc(sizeof(char) * 20);
    arr = (int *)malloc(sizeof(int) * x);

    printf("请输入顶点: ");
    for (int i = 0; i < x; i++)
        scanf("%s", str[i]);

    printf("请输入边数: ");
    scanf("%d", &t);

    e = (int *)malloc(sizeof(int) * (t + 3));
    ne = (int *)malloc(sizeof(int) * (t + 3));
    printf("请输入边: \n");
    for (int i = 0; i < t; i++)
    {
        char names[20];
        int a, b;
        scanf("%s", names);
        a = find(names);
        scanf("%s", names);
        b = find(names);
        // printf("a:%d, b:%d\n", a, b);
        add(a, b);
        add(b, a);
    }

    memset(arr, 0, sizeof(int) * x);
    printf("广度优先搜索的结果为: ");
    bfs();

    memset(arr, 0, sizeof(int) * x);
    printf("\n深度优先搜索的结果为: ");
    dfs(0);

    return 0;
}