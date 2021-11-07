#include<stdio.h>
int max1(int a, int b, int c)
{
	return (a > b ? a : b) > c ? (a > b ? a : b) : c;
}
int MaxSubSum(int a[], int left, int right)//分治
{
	if (left == right)
		return a[left];
	int center,maxleft,maxright;
	int maxleftborder, leftborder;
	int maxrightborder, rightborder;
	center = (left + right) / 2;
	maxleft = MaxSubSum(a, left, center);
	maxright = MaxSubSum(a, center + 1, right);
	maxleftborder = 0;
	leftborder = 0;
	for (int i = center; i >=left; i--)
	{
		leftborder += a[i];
		if (leftborder > maxleftborder)
			maxleftborder = leftborder;
	}
	maxrightborder = 0;
	rightborder = 0;
	for (int i = center+1; i<=right; i++)
	{
		rightborder += a[i];
		if (rightborder > maxrightborder)
			maxrightborder = rightborder;
	}
	return max1(maxleft, maxright, maxleftborder + maxrightborder);
}
int max2(int a, int b) 
{
	return a > b ? a : b;
}
int maxSubArray(int* nums, int numsSize) {//贪心算法
	int maxsum = -10000;
	if (numsSize == 1)
		return nums[0];
	int sum = 0;
	for (int i = 0; i < numsSize; i++)
	{
		sum += nums[i];
		maxsum = max2(maxsum, sum);
		if (sum < 0)
			sum = 0;
	}
	return maxsum;
}

int maxSubArray2(int* nums, int numsSize) { //动态规划
	int maxsum = -10000;
	if (numsSize == 1)
		return nums[0];
	int sum = nums[0];
	maxsum = sum;
	for (int i = 1; i < numsSize; i++)
	{
		sum = max2(sum + nums[i], nums[i]);
		maxsum = max2(sum, maxsum);
	}
	return maxsum;
}
