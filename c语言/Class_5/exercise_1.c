//双向链表的建立、插入和删除操作
//建立一个双向链表，输入一串整数并排序，同时可以实现插入节点、删除节点、查找节点、节点显示等操作。要求编写一个菜单，由用户选择执行哪一种操作。

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *prior;
    int score;
    struct node *next;

} LinkList;

LinkList *init();
void insert();
void del();
void find();
void prints();
void errors();

LinkList *head, *node, *tail;
int x;

//初始化node
LinkList *init()
{
    LinkList *node = (LinkList *)malloc(sizeof(LinkList));
    node->next = NULL;
    node->prior = NULL;
    return node;
}

//插入
void insert()
{
    node = init();
    scanf("%d", &node->score);
    LinkList *list = head->next;
    //从小到大排序
    for (list; list != tail; list = list->next)
    {
        //寻找链表中比插入数小的地方
        if (node->score > list->score)
        {

            while (node->score > list->score)
            {
                list = list->next;
            }
            // list -> score >= node->score
            node->next = list;
            node->prior = list->prior;
            list->prior->next = node;
            list->prior = node;
            return;
        }
    }
    if (list == tail)
    {
        node->next = head->next;
        node->prior = head;
        head->next->prior = node;
        head->next = node;
    }
}

//删除
void del()
{
    int t;
    scanf("%d", &t);
    LinkList *nextList = head->next;
    LinkList *array;
    while (nextList != tail && nextList->score <= t)
    {
        if (nextList->score == t)
        {
            array = nextList->prior;
            while (nextList->score == t)
            {
                nextList = nextList->next;
            }
            // nextList->score != t
            // array->score != t
            array->next = nextList;
            nextList->prior = array;
            break;
        }
        nextList = nextList->next;
    }
}

//按值查询
void find()
{
    int t;
    int flag = 0;
    int l = 0;
    int r = 0;
    int flagr = 0;
    int lr = 0;
    int rr = 0;
    int ir = 0;
    scanf("%d", &t);
    LinkList *nextList = head->next;
    int i = 0;
    while (nextList != tail && nextList->score <= t)
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
    nextList = tail->prior;
    while (nextList != head)
    {
        ir++;
        if (nextList->score == t)
        {
            flagr = 1;
            lr = ir;
            while (nextList && nextList->score == t)
            {
                ir++;
                nextList = nextList->prior;
            }
            rr = ir - 1;
            break;
        }
        nextList = nextList->prior;
    }

    if (flag)
        printf("%d位于正向链表第%d到第%d位，位于反向链表第%d位到第%d位\n", t, l, r, lr, rr);
    else
        printf("%d不存在于链表中\n", t);
}

void prints()
{
    printf("链表(Next): ");
    for (LinkList *list = head->next; list != tail; list = list->next)
    {
        if (list->next != tail)
            printf("%d->", list->score);
        else
            printf("%d", list->score);
    }
    puts("");
    printf("链表(Prior): ");
    for (LinkList *list = tail->prior; list != head; list = list->prior)
    {
        if (list->prior != head)
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
    tail = init();
    head->next = tail;
    tail->prior = head;
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