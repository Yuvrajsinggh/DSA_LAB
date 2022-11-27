#include <stdio.h>
#include <stdlib.h>

void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();

struct node
{
    int info;
    struct node *next;
};

struct node *start = NULL;

int main()
{
    char ch = 'y';
    int op;
    while (ch == 'y')
    {
        printf("\tMENU\t");
        printf("\n1. Create\n");
        printf("2. Display\n");
        printf("3. Insert at begining\n");
        printf("4. Insert at the end\n");
        printf("5. Insert at specified position\n");
        printf("6. Delete at begining\n");
        printf("7. Delete at the end\n");
        printf("8. Delete at specified position\n");
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
            insert_begin();
            display();
            break;

        case 4:
            insert_end();
            display();
            break;

        case 5:
            insert_pos();
            display();
            break;

        case 6:
            delete_begin();
            display();
            break;

        case 7:
            delete_end();
            display();
            break;

        case 8:
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
    return 0;
}

void create()
{
    struct node *temp, *ptr;
    int n, i, data;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Out of Memory Space\n");
    }
    printf("Enter the data value for the node : ");
    scanf("%d", &temp->info);
    printf("Enter the number of nodes : ");
    scanf("%d", &n);
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    for (i = 0; i < n; i++)
    {
        insert_end();
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
            printf(" %d ", ptr->info);
            ptr = ptr->next;
        }
    }
}

void insert_begin()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Out of Memory Space\n");
    }
    printf("\nEnter the data value for the node : ");
    scanf("%d", &temp->info);
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        temp->next = start;
        start = temp;
    }
}

void insert_end()
{
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Out of Memory Space\n");
    }
    printf("\nEnter the data value for the node : ");
    scanf("%d", &temp->info);
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
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
    scanf("%d", &temp->info);

    temp->next = NULL;
    if (pos == 0)
    {
        temp->next = start;
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
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

void delete_begin()
{
    struct node *ptr;
    if (ptr == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    else
    {
        ptr = start;
        start = start->next;
        printf("\nThe deleted element is : %d", ptr->info);
        free(ptr);
    }
}

void delete_end()
{
    struct node *temp, *ptr;
    if (start == NULL)
    {
        printf("List is empty\n");
    }
    else if (start->next == NULL)
    {
        ptr = start;
        start = NULL;
        printf("\nThe deleted element is : %d", ptr->info);
        free(ptr);
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        printf("The deleted element is : %d", ptr->info);
        free(ptr);
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
            printf("The deleted element is : %d", ptr->info);
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
            temp->next = ptr->next;
            printf("The deleted element is : %d", ptr->info);
            free(ptr);
        }
    }
}