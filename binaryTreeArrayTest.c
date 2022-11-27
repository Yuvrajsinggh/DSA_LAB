#include <stdio.h>
#include <stdlib.h>

int tree[100];

void set_root(int data, int lvalue, int rvalue) {
    if (tree[0] != '\0') printf("Tree already had root");
    else tree[0] = data;
    tree[1] = lvalue;
    tree[2] = rvalue;
}

void set_left(int data, int parentIndex) {
    if (tree[parentIndex] == '\0') printf("\nParent dosen't exist :( ");
    else tree[(parentIndex * 2) + 1] = data;
}

void set_right(int data, int parentIndex) {
    if (tree[parentIndex] == '\0') printf("\nParent dosen't exist :( ");
    else tree[(parentIndex * 2) + 2] = data;
}

void display() {
    printf("\n");
    for (int i = 0; i < 20; i++) {
        if (tree[i] != '\0') printf(" %d ", tree[i]);
        else printf(" - ");
    }
    
}

int main()
{
    int rdata, lvalue, rvalue;
    char ch = 'y';
    printf("Enter the Root : ");
    scanf("%d", &rdata);
    printf("\nEnter the Left children of Root : ");
    scanf("%d", &lvalue);
    printf("\nEnter the Right children of Root : ");
    scanf("%d", &rvalue);
    set_root(rdata, lvalue, rvalue);

    while (ch == 'y') {
        int parentIndex, ldata, rvdata;
        printf("\nEnter the Index of Parent node : ");
        scanf("%d", &parentIndex);
        printf("\nEnter the Left child of parent : ");
        scanf("%d", &ldata);
        set_left(ldata, parentIndex);
        printf("\nEnter the Right child of parent : ");
        scanf("%d", &rvdata);
        set_right(rvdata, parentIndex);
        printf("\nDo you want to continue (y or n) : ");
        scanf("%s", &ch);
    }
    

    display();

    return 0;
}