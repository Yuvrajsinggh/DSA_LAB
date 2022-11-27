#include <stdio.h>
#include <stdlib.h>

struct node 
{
    struct node* prev;
    int data;
    struct node* next;
};

