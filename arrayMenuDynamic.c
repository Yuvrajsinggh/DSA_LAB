#include <stdio.h>
#include <stdlib.h>

void display(int size, int *x)
{
    printf("Given array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", *(x + i));
    printf("\n");
}

void read(int *x, int size)
{
    printf("Enter the elements (space/newline seperated): ");
    for (int i = 0; i < size; i++)
        scanf("%d", x + i);
}

void insert(int *x, int size, int ele, int pos)
{
    for (int i = size - 1; i >= pos; i--)
        x[i + 1] = x[i];
    x[pos] = ele;
    printf("Item Inserted\n");
    size = size + 1;

    printf("Given array after Insertion : ");
    for (int i = 0; i < size; i++)
        printf("%d ", *(x + i));
    printf("\n");
}

void delete (int *x, int size, int pos)
{
    for (int i = pos; i <= size - 1; i++)
        x[i] = x[i + 1];
    size = size - 1;

    printf("Given array after Deletion : ");
    for (int i = 0; i < size; i++)
        printf("%d ", *(x + i));
    printf("\n");
}

void reverse(int *x, int size)
{
    int low = 0;
    int high = size - 1;
    while (low < high)
    {
        int temp = x[high];
        x[high] = x[low];
        x[low] = temp;
        low++;
        high--;
    }

    printf("Reverse Array : ");
    for (int i = 0; i < size; i++)
        printf("%d ", *(x + i));
    printf("\n");
}

void search(int *x, int size, int ele)
{
    for (int i = 0; i < size; i++)
        if (x[i] == ele)
            printf("Index is %d\n", i);

}

void update(int *x, int pos, int ele, int size)
{
    x[pos] = ele;

    printf("Updated Array : ");
    for (int i = 0; i < size; i++)
        printf("%d ", *(x + i));
    printf("\n");
}

void append(int *x, int ele, int size)
{
    x[size] = ele;
    size = size + 1;

    printf("Appended Array : ");
    for (int i = 0; i < size; i++)
        printf("%d ", *(x + i));
    printf("\n");
}

int merge(int *x, int *y, int size1, int size2)
{
    int size3 = size1 + size2;
    int *arr2 = calloc(size3, sizeof(int));
    if (arr2 == NULL)
    {
        printf("Unable to allocate memory\n");
        return -1;
    }
    int i, j;
    for (i = 0; i < size1; i++)
        arr2[i] = x[i];
    for (i = 0; i < size2; i++)
        arr2[i + size1] = y[i];

    printf("Merged Array : ");
    for (i = 0; i < size3; i++)
        printf("%d ", *(arr2 + i));
    printf("\n");
    free(arr2);
}

void sort(int *x, int size)
{
    int temp, i, j;
    for (i = 0; i < size; i++)
        for (j = i + 1; j < size; j++)
            if (x[i] > x[j])
            {
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }

    printf("Sorted Array : ");
    for (i = 0; i < size; i++)
        printf("%d ", *(x + i));
    printf("\n");
}

int main()
{
    int n, ele, pos;
    char ch = 'y', op;
    printf("Size of the array: ");
    scanf("%d", &n);
    int *arr = calloc(n, sizeof(int));
    if (arr == NULL)
    {
        printf("Unable to allocate memory\n");
        return -1;
    }
    read(arr, n);


    while (ch='y')
    {
        printf("\nOperations\n");

        printf("\n1 : Display");
        printf("\n2 : Insert");
        printf("\n3 : Delete");
        printf("\n4 : Reverse");
        printf("\n5 : Search");
        printf("\n6 : Update");
        printf("\n7 : Append");
        printf("\n8 : Merge");
        printf("\n9 : Sort");

    printf("\nChoose an option from above : ");
    scanf("%d", &op);

    switch (op)
    {
    case 1 :
        display(n, arr);
        free(arr);
        break;
    case 2 :
        printf("Enter the Element to be Inserted : ");
        scanf("%d", &ele);
        printf("Enter the position of Insertion : ");
        scanf("%d", &pos);
        insert(arr, n, ele, pos);
        free(arr);
        break;
    case 3 : 
        printf("Enter the position of Element you want to Delete : ");
        scanf("%d", &pos);
        delete (arr, n, pos);
        free(arr);
        break;
    case 4 :
        reverse(arr, n);
        free(arr);
        break;
    case 5 :
        printf("Enter the Element you want to Search : ");
        scanf("%d", &ele);
        search(arr, n, ele);
        free(arr);
        break;
    case 6 :
        printf("Enter the Element to be Updated : ");
        scanf("%d", &ele);
        printf("Enter the position of Element : ");
        scanf("%d", &pos);
        update(arr, pos, ele, n);
        free(arr);
        break;
    case 7 :
        printf("Enter the element you want to Append : ");
        scanf("%d", &ele);
        append(arr, ele, n);
        free(arr);
        break;
    case 8 :
        printf("Size of the Second array: ");
        int n2;
        scanf("%d", &n2);
        int *arr1 = calloc(n2, sizeof(int));
        if (arr1 == NULL)
        {
            printf("Unable to allocate memory\n");
            return -1;
        }
        read(arr1, n2);
        merge(arr, arr1, n, n2);
        free(arr1);
        free(arr);
        break;
    case 9 :
        sort(arr, n);
        free(arr);
        break;
    default:
        break;
    }
    printf("\nDo you want to continue(y or n) : ");
    scanf("%s", &ch);
    }
    return 0;
}