#include <stdio.h>
#include <stdlib.h>

struct binaryTree {
    struct binaryTree *lchild;
    int data;
    struct binaryTree *rchild;
};

struct binaryTree* create () {
    int data;
    struct binaryTree* newNode = (struct binaryTree*) malloc(sizeof(struct binaryTree));
    printf("\nEnter data (-1 for no node) : ");
    scanf("%d", &data);
    if (data == -1) return 0;
    newNode -> data = data;
    printf("\nEnter left child of %d : ", data);
    newNode -> lchild = create();
    printf("\nEnter right child of %d : ", data);
    newNode -> rchild = create();
    newNode -> lchild = newNode -> rchild = NULL;
    return newNode;
}

void print() {
    struct binaryTree* head;
    
}

int main() {
    struct binaryTree *root;
    root = create();
    // print(root);
    return 0;
}