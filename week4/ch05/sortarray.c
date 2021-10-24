#include<stdio.h>
int* sortArrayByParityII(int* nums, int numsSize) {
    int* a = (int*)malloc(sizeof(int) * (numsSize / 2));
    int* b = (int*)malloc(sizeof(int) * (numsSize / 2));
    int n = -1, m = -1;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] % 2 == 0)
        {
            m++;
            a[m] = nums[i];
        }
        if (nums[i] % 2 != 0)
        {
            n++;
            b[n] = nums[i];
        }
    }
    m = -1;
    n = -1;
    for (int i = 0; i < numsSize; i++)
    {
        if (i % 2 == 0)
        {
            m++;
            nums[i] = a[m];
        }
        if (i % 2 != 0)
        {
            n++;
            nums[i] = b[n];
        }

    }
    return nums;
}
int main()
{
    int a[4] = { 4,2,5,7 };
    int* b;
    b = sortArrayByParityII(a, 4);
    for (int i = 0; i < 4; i++)
    {
        printf("%d\t", b[i]);
    }
    return 0;
}
