#include<stdio.h>
int* sortArrayByParity(int* nums, int numsSize) {
    int* a = (int*)malloc(sizeof(int) * numsSize);
    int n = -1;
    for (int i = 0; i < numsSize; i++)
    {

        if (nums[i] % 2 == 0)
        {
            n++;
            a[n] = nums[i];
        }

    }
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] % 2 != 0)
        {
            n++;
            a[n] = nums[i];

        }
    }
    return a;
}
int main() {
    int a[4] = { 3,1,4,2 };
    int* b;
    b = sortArrayByParity(a, 4);
    int i;
    for (i = 0; i < 4; i++)
    {
        printf("%d\t", b[i]);
    }

}
