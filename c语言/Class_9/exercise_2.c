//尾插法

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    struct node *next;
    char val[20];
} LinkLisk;

LinkLisk *node;
LinkLisk **head, **tail;
int *arr;
char str[20];
char strs[20];
int x, t;

LinkLisk *init(char val[])
{
    LinkLisk *node = (LinkLisk *)malloc(sizeof(LinkLisk));
    strcpy(node->val, val);
    node->next = NULL;
    return node;
}

int find(char val[])
{
    for (int i = 0; i < x; i++)
    {
        if (!strcmp(head[i]->val, val))
        {
            return i;
        }
    }
    return 0;
}

void add(char val[], char vals[])
{
    int idx = find(val);
    node = init(vals);
    tail[idx]->next = node;
    tail[idx] = node;
}

void dfs(LinkLisk *nodes)
{
    int idx = find(nodes->val);
    arr[idx] = 1;
    printf("%s ", nodes->val);
    for (LinkLisk *i = head[idx]; i; i = i->next)
        if (!arr[find(i->val)])
            dfs(i);
}

void bfs()
{
    node = init(head[0]->val);
    LinkLisk *tail = node;
    while (node)
    {
        int idx = find(node->val);
        if (!arr[idx])
        {
            arr[idx] = 1;
            for (LinkLisk *i = head[idx]->next; i; i = i->next)
            {
                LinkLisk *nodes = init(i->val);
                tail->next = nodes;
                tail = nodes;
            }
            printf("%s ", node->val);
        }
        node = node->next;
    }
}

int main()
{
    printf("请输入顶点数:");
    scanf("%d", &x);
    head = (LinkLisk **)malloc(sizeof(LinkLisk *) * x);
    tail = (LinkLisk **)malloc(sizeof(LinkLisk *) * x);
    arr = (int *)malloc(sizeof(int) * x);

    printf("请输入顶点: ");
    for (int i = 0; i < x; i++)
    {
        scanf("%s", str);
        head[i] = init(str);
        tail[i] = head[i];
        // printf("str:%s, arr:%d\n", head[i]->val, arr[i]);
    }
    printf("请输入边数: ");
    scanf("%d", &t);
    printf("请输入边: \n");
    for (int i = 0; i < t; i++)
    {
        scanf("%s", str);
        scanf("%s", strs);
        add(str, strs);
        add(strs, str);
    }
    memset(arr, 0, sizeof(int) * x);
    printf("广度优先搜索的结果为: ");
    bfs();

    memset(arr, 0, sizeof(int) * x);
    printf("\n深度优先搜索的结果为: ");
    dfs(head[0]);

    return 0;
}