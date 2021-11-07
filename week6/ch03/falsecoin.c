#include<stdio.h>
int findwrongcoin( int a[],int left,int right)
{
	int i,sum=0,sum1=0,re;
	int N = (left + right+1) / 2;
	
	if ((right + 1 - left) %2 == 0)
	{
		if ((left < right) && (left + 1 == right))//只剩下两枚硬币时
	    {
		if (a[left] < a[right])
			re = left;
		else
			re = right;
		return re;
	    }
		for (i = left; i < N; i++)
		{
			sum += a[i];
		}
		for (i = N; i < right + 1; i++)
		{
			sum1 += a[i];
		}
		if (sum > sum1)
			re = findwrongcoin(a, N, right);
		else
			re = findwrongcoin(a, left, N - 1);
	}
	else 
	{
		if ((left < right) && (left + 2 == right))
		{
			if (a[left] < a[right])
				re = left;
			else if (a[left] > a[right])
				re = right;
			else
				re = N;
		}
		for (i = left; i < N; i++)
		{
			sum += a[i];
		}
		for(i = N+1; i < right+1; i++)
		{
			sum1 += a[i];
		}
		if (sum > sum1)
			re = findwrongcoin(a, N + 1, right);
		else if (sum < sum1)
			re = findwrongcoin(a, left, N - 1);
		else
			re = N;
	}
	return re;
}       
int main()
{
	int a[7] = { 2,2,2,2,2,1,2};//硬币编号与数组下标一致
	int b[10] = { 2,2,2,2,2,1,2,2,2,2 };
	int c = findwrongcoin(a, 0, 6);
	int d = findwrongcoin(b, 0, 6);

	printf("(奇数)假硬币的编号为：");
	printf("%d", c);
	printf("\n(偶数)假硬币的编号为：");
	printf("%d", d);

	return 0;
}
