//单向链表的建立、插入和删除操作。
//建立一个单向链表，输入一串整数并排序，同时可以实现插入节点、删除节点、查找节点、节点显示等操作。要求编写一个菜单，由用户选择执行哪一种操作。

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int score;
    struct node *next;
} LinkList;

LinkList *init();
void insert();
void del();
void find();
void prints();
void errors();

LinkList *head, *node;
int x;

//初始化node
LinkList *init()
{
    LinkList *node = (LinkList *)malloc(sizeof(LinkList));
    node->next = NULL;
    return node;
}

//插入
void insert()
{
    node = init();
    scanf("%d", &node->score);
    LinkList *list = head->next;
    LinkList *arrayList;
    //从小到大排序
    for (list; list != NULL; list = list->next)
    {
        //寻找链表中比插入数小的地方
        if (node->score > list->score)
        {

            while (list && node->score > list->score)
            {
                arrayList = list;
                list = list->next;
            }

            LinkList *array = arrayList->next;
            arrayList->next = node;
            node->next = array;
            return;
        }
    }
    if (list == NULL)
    {
        LinkList *array = head->next;
        head->next = node;
        node->next = array;
    }
}

//删除
void del()
{
    int t;
    scanf("%d", &t);
    LinkList *list = head;
    LinkList *nextList = list->next;
    LinkList *array;
    while (nextList && nextList->score <= t)
    {
        if (nextList->score == t)
        {
            array = list;
            while (nextList->score == t)
            {
                list = list->next;
                nextList = list->next;
            }
            array->next = list->next;
            break;
        }
        list = list->next;
        nextList = list->next;
    }
}

//按值查询
void find()
{
    int t;
    int flag = 0;
    int l = 0;
    int r = 0;
    scanf("%d", &t);
    LinkList *nextList = head->next;
    int i = 0;
    while (nextList && nextList->score <= t)
    {
        i++;
        if (nextList->score == t)
        {
            flag = 1;
            l = i;
            while (nextList && nextList->score == t)
            {
                i++;
                nextList = nextList->next;
            }
            r = i - 1;
            break;
        }
        nextList = nextList->next;
    }
    if (flag)
        printf("%d位于链表第%d到第%d位\n", t, l, r);
    else
        printf("%d不存在于链表中\n", t);
}

void prints()
{
    printf("链表：");
    for (LinkList *list = head->next; list != NULL; list = list->next)
    {
        if (list->next)
            printf("%d->", list->score);
        else
            printf("%d", list->score);
    }
    puts("");
}

void errors(int m)
{
    if (m)
        printf("没有输入正确的数字请重新输入\n");
    printf("请输入对应的数字选择相应的操作\n");
    printf("1:插入\n");
    printf("2:删除\n");
    printf("3:按值查询\n");
    scanf("%d", &x);
}

int main()
{
    head = init();
    printf("输入整数的个数：\n");
    scanf("%d", &x);
    printf("输入：%d位整数\n", x);
    printf("生成：");
    while (x--)
    {
        insert();
    }
    prints();

    while (1)
    {
        errors(0);
        switch (x)
        {
        case 1:
            printf("插入: ");
            insert();
            prints();
            break;
        case 2:
            printf("删除: ");
            del();
            prints();
            break;
        case 3:
            printf("查询: ");
            find();
            prints();
            break;
        default:
            errors(1);
        }
    }
    return 0;
}