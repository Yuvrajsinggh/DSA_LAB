#include <stdio.h>
#include <stdlib.h>

void create();
void insert_end();
void display();
void insert_pos();
void delete_pos();

struct node 
{
    struct node* prev;
    int data;
    struct node* next;
};

struct node* start = NULL;

void main()
{
    char ch = 'y';
    int op;
    while (ch == 'y')
    {
        printf("\tMENU\t");
        printf("\n1. Create\n");
        printf("2. Display\n");
        printf("3. Insert at specified position\n");
        printf("4. Delete at specified position\n");
        printf("\nChoose an option from above : ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            create();
            display();
            break;

        case 2:
            display();
            break;

        case 3:
            insert_pos();
            display();
            break;

        case 4:
            delete_pos();
            display();
            break;

        default:
            printf("Wrong Choice\n");
            break;
        }
        printf("\n\nDo you want to continue(y or n) : ");
        scanf("%s", &ch);
    }
}

void create()
{
    struct node *temp, *ptr;
    int i, n;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL)
    {
        printf("\nOut of Memory Space :(\n");
    }
    printf("Enter the data value for the node : ");
    scanf("%d", &temp->data);
    printf("Enter the number of nodes : ");
    scanf("%d", &n);
    if(start == NULL) 
    {
        temp -> next = start;
        temp -> prev = NULL;
        start = temp;
    }
    else 
    {
        ptr = start;
        while (ptr -> next != NULL)
        {
            ptr = ptr -> next;
        }
        ptr -> next = temp;
        temp -> prev = ptr;
        temp -> next = NULL;
    }
    for (i = 0; i < n; i++)
    {
        insert_end();
    }
}


void insert_end()
{
    struct node *temp, *ptr;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL)
    {
        printf("\nOut of Memory Space :(\n");
    }
    printf("Enter the data value for the node : ");
    scanf("%d", &temp->data);
    if(start == NULL) 
    {
        temp -> next = start;
        temp -> prev = NULL;
        start = temp;
    }
    else 
    {
        ptr = start;
        while (ptr -> next != NULL)
        {
            ptr = ptr -> next;
        }
        ptr -> next = temp;
        temp -> prev = ptr;
        temp -> next = NULL;
    }
}


void display()
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    else
    {
        ptr = start;
        printf("\nThe List elements are : \n");
        while (ptr != NULL)
        {
            printf(" %d ", ptr->data);
            ptr = ptr->next;
        }
    }
}

void insert_pos()
{
    struct node *ptr, *temp;
    int i, pos;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Out of Memory space\n");
        return;
    }
    printf("\nEnter the position for the new node to be inserted : ");
    scanf("%d", &pos);
    printf("Enter the data value for the node : ");
    scanf("%d", &temp->data);

    if (pos == 0)
    {
        temp -> prev = NULL;
        temp  -> next = start;
        start = temp;
    }
    else
    {
        for (i = 0, ptr = start; i < pos - 1; i++)
        {
            ptr = ptr->next;
            if (ptr == NULL)
            {
                printf("Position not found\n");
                return;
            }
        }
        temp -> next = ptr -> next;
        ptr -> next -> prev = temp;
        ptr -> next = temp;
        temp -> prev = ptr;
    }
}

void delete_pos()
{
    int i, pos;
    struct node *temp, *ptr;
    if (start == NULL)
    {
        printf("The list is Empty\n");
    }
    else
    {
        printf("\nEnter the position to be deleted : ");
        scanf("%d", &pos);
        if (pos == 0)
        {
            ptr = start;
            start = start->next;
            start -> prev = NULL;
            printf("The deleted element is : %d", ptr->data);
            free(ptr);
        }
        else
        {
            ptr = start;
            for (i = 0; i < pos; i++)
            {
                temp = ptr;
                ptr = ptr->next;
                if (ptr == NULL)
                {
                    printf("Position not found\n");
                    return;
                }
            }
            ptr -> next -> prev = temp;
            temp -> next = ptr -> next;
            printf("The deleted element is : %d", ptr -> data);
            free(ptr);
        }
    }
}