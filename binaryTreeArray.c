// C implementation of tree using array numbering starting from 0 to n-1.
#include <stdio.h>
#include <stdlib.h>

void root();
void set_left();
void set_ileft();
void set_right();
void set_iright();
void display();

char tree[100];

void main()
{
    root();
    set_left();
    set_right();
    display();
}

void root()
{
    int data, lchild, rchild;
    char ch, op;
    printf("Enter the value of root node : ");
    scanf("%d", &data);
    tree[0] = data;
    printf("\nEnter the Left child of root : ");
    scanf("%d", &lchild);
    tree[1] = lchild;
    printf("\nEnter the Right child of root : ");
    scanf("%d", &rchild);
    tree[2] = rchild;
}

void set_left()
{
    int lchild, rchild, li = 1, ri = 1;
    char ch, op;

    printf("\nDo you want to make left child of root as parent node (y or n) : ");
    scanf("%s", &ch);

    while (ch == 'y')
    {
        printf("\nEnter the children of Left child -> \n");
        printf("\nEnter the Left child : ");
        scanf("%d", &lchild);
        printf("\nEnter the Right child : ");
        scanf("%d", &rchild);
        tree[(li * 2) + 1] = lchild;
        tree[(ri * 2) + 2] = rchild;
        printf("\nDo you want to make %d as parent node (y or n) : ", lchild);
        scanf("%s", &op);
        li = (li * 2) + 1;
        ri = li;
        if (op == 'y')
        {
            set_ileft(li, ri);
        }
    }
}

void set_ileft(int li, int ri)
{
    int lchild, rchild;
    char op;
    printf("\nEnter the children of Left child -> \n");
    printf("\nEnter the Left child : ");
    scanf("%d", &lchild);
    printf("\nEnter the Right child : ");
    scanf("%d", &rchild);
    tree[(li * 2) + 1] = lchild;
    tree[(ri * 2) + 2] = rchild;
    printf("\nDo you want to make %d as parent node (y or n) : ", rchild);
    scanf("%s", &op);
    if (op == 'y')
    {
        set_ileft(li, ri);
    }
}

void set_right()
{

    int lchild, rchild, li = 2, ri = 2;
    char ch, op;

    printf("\nDo you want to make right child of root as parent node (y or n) : ");
    scanf("%s", &ch);

    while (ch == 'y')
    {
        printf("\nEnter the children of Right child -> \n");
        printf("\nEnter the Left child : ");
        scanf("%d", &lchild);
        printf("\nEnter the Right child : ");
        scanf("%d", &rchild);
        tree[(li * 2) + 1] = lchild;
        tree[(ri * 2) + 2] = rchild;
        printf("\nDo you want to make %d as parent node (y or n) : ", rchild);
        scanf("%s", &op);
        ri = (ri * 2) + 2;
        li = ri;
        if (op == 'y')
        {
            set_iright(li, ri);
        }
    }
}

void set_iright(int li, int ri)
{
    int lchild, rchild;
    char op;
    printf("\nEnter the children of Right child -> \n");
    printf("\nEnter the Left child : ");
    scanf("%d", &lchild);
    printf("\nEnter the Right child : ");
    scanf("%d", &rchild);
    tree[(li * 2) + 1] = lchild;
    tree[(ri * 2) + 2] = rchild;
    printf("\nDo you want to make %d as parent node (y or n) : ", rchild);
    scanf("%s", &op);
    if (op == 'y')
    {
        set_iright(li, ri);
    }
}

void display()
{
    printf("\n");
    for (int i = 0; i < 30; i++)
    {
        if (tree[i] != '\0')
        {
            printf(" %d ", tree[i]);
        }
        else
        {
            printf(" - ");
        }
    }
}