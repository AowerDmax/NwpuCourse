//搜索二叉树的建立、插入、删除以及遍历
//搜索二叉树： 若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值； 若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值； 它的左、右子树也分别为二叉排序树。
//编写一个菜单，由用户选择执行哪一种操作。

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node
{
    struct node *left;
    int val;
    struct node *right;

} TreeNode;

typedef struct list
{
    struct list *next;
    TreeNode *val;
} LinkList;

TreeNode *init(int x);
LinkList *listInit(TreeNode *n);
void insert();
void del();
void preorder(TreeNode *n);
void inorder(TreeNode *n);
void postorder(TreeNode *n);
void dfsorder(TreeNode *n);
void bfsorder(TreeNode *n);
void errors(int m);
void prints();

TreeNode *head, *node;
LinkList *list, *listhead;
int x;

TreeNode *init(int x)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->left = NULL;
    node->right = NULL;
    node->val = x;
    return node;
}

LinkList *listInit(TreeNode *n)
{
    LinkList *list = (LinkList *)malloc(sizeof(LinkList));
    list->next = NULL;
    list->val = n;
    return list;
}

void insert()
{
    node = init(0);
    scanf("%d", &node->val);

    //二叉搜索树初始化
    if (!head)
    {
        head = node;
        printf("%d\n", head->val);
        return;
    }
    TreeNode *tree = head;
    TreeNode *preTree;
    int flag = 0;
    //二叉搜索树 插入操作
    do
    {
        if (tree->val >= node->val)
        {
            flag = 0;
            preTree = tree;
            tree = tree->left;
            // printf("node:%d, treeVal:%d, flag:%d\n", node->val, preTree->val, flag);
        }
        else
        {
            flag = 1;
            preTree = tree;
            tree = tree->right;
            // printf("node:%d, treeVal:%d, flag:%d\n", node->val, preTree->val, flag);
        }

    } while (tree);

    if (flag)
    {
        preTree->right = node;
    }
    else
    {
        preTree->left = node;
    }
    // inorder(head);
    // printf("\n");
}

void del()
{
    scanf("%d", &x);
    //先找到x所在的位置
    TreeNode *tree = head;
    TreeNode *preTree;
    //二叉搜索树寻找位置
    do
    {
        if (tree && tree->val == x)
            break;
        if (tree && tree->val > x)
        {
            preTree = tree;
            tree = tree->left;
        }
        else if (tree && tree->val < x)
        {
            preTree = tree;
            tree = tree->right;
        }
        else
        {
            printf("二叉搜索树中不存在数%d,请重新输入", x);
            return;
        }
    } while (1);
    if (!tree->left || !tree->right)
    {
        if (tree == head)
            head = !tree->left ? tree->right : tree->left;
        else if (preTree->left == tree)
            preTree->left = !tree->left ? tree->right : tree->left;
        else if (preTree->right == tree)
            preTree->right = !tree->left ? tree->right : tree->left;
        return;
    }

    TreeNode *nodeleft, *noderight;

    nodeleft = tree->left;
    noderight = tree->right;
    if (tree == head)
        head = nodeleft;
    else if (preTree->left == tree)
        preTree->left = nodeleft;
    else if (preTree->right == tree)
        preTree->right = nodeleft;
    while (nodeleft->right)
    {
        nodeleft = nodeleft->right;
    }
    nodeleft->right = noderight;
}

//前序遍历
void preorder(TreeNode *n)
{
    if (!n)
        return;
    printf("%d ", n->val);
    preorder(n->left);
    preorder(n->right);
}

//中序遍历
void inorder(TreeNode *n)
{
    if (!n)
        return;
    inorder(n->left);
    printf("%d ", n->val);
    inorder(n->right);
}
//后序遍历
void postorder(TreeNode *n)
{
    if (!n)
        return;
    postorder(n->left);
    postorder(n->right);
    printf("%d ", n->val);
}
//深度优先遍历
void dfsorder(TreeNode *n)
{
    if (!n)
        return;
    printf("%d ", n->val);
    dfsorder(n->left);
    dfsorder(n->right);
}
//广度优先遍历
void bfsorder(TreeNode *n)
{
    list = listInit(n);
    LinkList *tail = list;
    while (list)
    {
        node = list->val;
        printf("%d ", node->val);
        if (node->left)
        {
            tail->next = listInit(node->left);
            tail = tail->next;
        }
        if (node->right)
        {
            tail->next = listInit(node->right);
            tail = tail->next;
        }
        list = list->next;
    }
}
void errors(int m)
{
    if (m)
        printf("没有输入正确的数字请重新输入\n");
    printf("请输入对应的数字选择相应的操作\n");
    printf("1:插入\n");
    printf("2:删除\n");
    scanf("%d", &x);
}

void prints()
{
    printf("head节点为:%d\n", head->val);
    printf("遍历后的二叉排序树为：");
    inorder(head);
    printf("\n");
    printf("前序遍历后的二叉排序树为：");
    preorder(head);
    printf("\n");
    printf("中序遍历后的二叉排序树为：");
    inorder(head);
    printf("\n");
    printf("后序遍历后的二叉排序树为：");
    postorder(head);
    printf("\n");
    printf("深度优先遍历后的二叉排序树为：");
    dfsorder(head);
    printf("\n");
    printf("广度优先遍历后的二叉排序树为：");
    bfsorder(head);
    printf("\n");
}

int main()
{
    head = NULL;
    printf("输入整数的个数：\n");
    scanf("%d", &x);
    printf("输入：%d位整数\n", x);
    printf("输入的数据为: \n");
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
            printf("1:请输入待插入的数据\n");
            insert();
            prints();
            break;
        case 2:
            printf("2:请输入待删除的数据\n");
            del();
            prints();
            break;
        default:
            errors(1);
        }
    }
    return 0;
}
