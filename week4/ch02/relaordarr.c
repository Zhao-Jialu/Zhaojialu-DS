#include<stdio.h>
#include<stdlib.h>
void relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size) {
    int i, j, n = 0;
    int* returnSize=(int*)malloc(sizeof(int)*arr1Size);
    for (i = 0; i < arr2Size; i++)
    {
        for (j = 0; j <arr1Size; j++)
        {
            if (arr1[j] == arr2[i])
            {
                returnSize[n] = arr1[j];
                arr1[j] = -1;
                n++;
            }
        }
    }
    int m = n;
    for (i = 0; i < arr1Size; i++)
    {
        if (arr1[i] != -1)
        {
            returnSize[m] = arr1[i];
            m++;
        }
    }
    for (i = n + 1; i < arr1Size; i++)
    {
        for (j = n ; (j-n) < arr1Size - i; j++)
        {
            if (returnSize[j] > returnSize[j + 1])
            {
                int tmp = returnSize[j];
                returnSize[j] = returnSize[j + 1];
                returnSize[j + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < 6; i++)
    {
        printf("%d\t", returnSize[i]);
    }
    free(returnSize);
}

int main()
{
    int a1[6] = { 1,2,3,7,6,5 };
    int a2[3] = { 2,3,5 };
    relativeSortArray(a1, 6, a2, 3);
}
   
