//求逆波兰表达式
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[100];

typedef struct node
{
    int val;
    struct node *next;
} LinkList;

/**
 * -1 是 +
 * -2 是 -
 * -3 是 *
 * -4 是 /
 */
char strs[] = {'0', '+', '-', '*', '/'};
//树
typedef struct treeNode
{
    int val;
    struct treeNode *l;
    struct treeNode *r;
} Tree;
//栈
typedef struct treeList
{
    Tree *tr;
    struct treeList *next;
} TreeList;

Tree *tr;
TreeList *tt, *hh, *tree;
LinkList *tail, *node, *top;

LinkList *init(int x)
{
    LinkList *node = (LinkList *)malloc(sizeof(LinkList));
    node->next = NULL;
    node->val = x;
    return node;
}

Tree *treeInit(int x)
{
    Tree *node = (Tree *)malloc(sizeof(Tree));
    node->l = NULL;
    node->r = NULL;
    node->val = x;
    return node;
}

TreeList *listInit(Tree *tr)
{
    TreeList *node = (TreeList *)malloc(sizeof(TreeList));
    node->tr = tr;
    node->next = NULL;
    return node;
}

void inOrder(Tree *ee)
{
    if (!ee)
        return;
    int flag = 0;
    if (ee->val <= -10)
    {
        ee->val += 10;
        flag = 1;
    }
    if (flag)
        printf("(");
    inOrder(ee->l);
    if (ee->val < 0)
        printf("%c ", strs[-1 * ee->val]);
    else
        printf("%d ", ee->val);
    inOrder(ee->r);
    if (flag)
        printf(")");
}

int main()
{
    printf("请输入逆波兰表达式:\n");
    gets(str);
    tail = init(1);
    top = tail;
    tt = NULL;
    hh = NULL;
    // for (int i = 0; str[i] != '\0'; i++)
    //     printf("str[i]:%d\n", str[i]);
    for (int i = 0; str[i];)
    {
        char c = str[i];
        // printf("c:%c\n", c);
        if (c == ' ')
        {
            i++;
            continue;
        }
        if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            //出栈
            int a = top->val;
            top = top->next;
            int b = top->val;
            for (int k = 1; k <= 4; k++)
            {
                if (strs[k] == c)
                {
                    tr = treeInit(-1 * k);

                    tr->r = hh->tr;
                    hh = hh->next;

                    tr->l = hh->tr;
                    hh = hh->next;

                    if ((tr->l->val < 0 && tr->l->val >= -2) && tr->val < -2)
                    {
                        tr->l->val -= 10;
                    }
                    if ((tr->r->val < 0 && tr->r->val >= -2) && tr->val < -2)
                    {
                        tr->r->val -= 10;
                    }
                    tt = listInit(tr);
                    tt->next = hh;
                    hh = tt;
                }
            }

            //计算后入栈
            if (c == '+' || c == '-')
                top->val = c == '+' ? b + a : b - a;
            if (c == '*' || c == '/')
                top->val = c == '*' ? b * a : b / a;
            // printf("a:%d, b:%d, c:%c, val:%d\n", a, b, c, top->val);
            i++;
            continue;
        }
        //取出数字， 需要考虑数字的位数
        int x = 0;
        int num = c - '0';

        do
        {
            num = str[i++] - '0';
            if (num >= 0 && num <= 9)
            {
                x = x * 10 + num;
                // printf("x:%d\n", x);
            }
            else
                break;
        } while (1);
        node = init(x);

        tr = treeInit(x);
        tt = listInit(tr);
        tt->next = hh;
        hh = tt;
        //入栈
        node->next = top;
        top = node;
        // printf("i:%d\n", i);
    }
    inOrder(hh->tr);
    printf("计算结果是%d\n", top->val);
    return 0;
}