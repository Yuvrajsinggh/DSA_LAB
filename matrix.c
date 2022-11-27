#include<stdio.h>
#include<stdlib.h>

int main()
{
    int row1, row2, col1, col2, op;
    char ch ='y';
    printf("Enter the size of first matrix -> \n");
    printf("Enter row size : ");
    scanf("%d", &row1);
    printf("Enter column size : ");
    scanf("%d", &col1);
    int mat1[row1][col1], resmat[100][100];

    printf("\nEnter the elements of first matrix -> \n");
    for(int i = 0; i < row1; i++)
    {
        for(int j = 0; j < col1; j++) 
        {
            printf("Enter the element at %d row and %d column : ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("\nFirst Matrix -> \n");
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            printf("%d\t", mat1[i][j]);
        }printf("\n");
    }
    

    printf("\nEnter the size of second matrix -> \n");
    printf("Enter row size : ");
    scanf("%d", &row2);
    printf("Enter column size : ");
    scanf("%d", &col2);
    int mat2[row2][col2];

    printf("\nEnter the elements of second matrix -> \n");
    for(int i = 0; i < row2; i++)
    {
        for(int j = 0; j < col2; j++) 
        {
            printf("Enter the element at %d row and %d column : ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }

    printf("\nSecond Matrix -> \n");
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            printf("%d\t", mat2[i][j]);
        }printf("\n");
    }

    while (ch == 'y')
    {
        printf("\nOperations on Matrices -> \n");
        printf("\t 1.Addition");
        printf("\t 2.Multiplication");
        printf("\t 3.Transpose");
        printf("\t 4.Determinant");
        printf("\nChoose an option from above : ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
        if (row1 == row2 && col1 == col2)
        {
        printf("\nAddition of Matrices - \n");
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col1; j++)
            {
                resmat[i][j] = mat1[i][j] + mat2[i][j];
            }
        }
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col1; j++)
            {
                printf("%d\t", resmat[i][j]);
            } printf("\n");
        }
        } else {printf("\nAddition is not possible\n");}
            break;

        case 2:
        if (row1 == col2 && col1 == row2)
        {
        printf("\nMultiplication of Matrices - \n");
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col2; j++)
            {
                int sum = 0;
                for (int k = 0; k < col1; k++)
                {
                    sum += mat1[i][k] * mat2[k][j];
                }
                resmat[i][j] = sum;
            }
        }
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col1; j++)
            {
                printf("%d\t", resmat[i][j]);
            } printf("\n");
        }
        } else {printf("\nMultiplication is not possible\n");}
            break;

        case 3:
        printf("\nTranspose of Matrix -\n");
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col1; j++)
            {
                resmat[j][i] = mat1[i][j];
            }
        }
        for (int i = 0; i < col1; i++)
        {
            for (int j = 0; j < row1; j++)
            {
                printf("%d\t", resmat[i][j]);
            } printf("\n");
        }

        case 4:
            break;

        default:
            break;
        }

        printf("Do you want to Continue (y or n) : "); 
        scanf("%s", &ch);
    } 
    

    return 0;
}