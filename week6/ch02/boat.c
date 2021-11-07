#include<stdio.h>
int minboat(int N, int a[],int maxweigt)//N为要过河的人数，a数组存储了每个人的体重（按升序排列），maxweight为船能承载的最大体重 
{
	int p1 = 0,p2=N-1,k=0;
	while (N > 0)
	{
		if (a[p1] + a[p2] > maxweigt)
		{
			p2--;
			k++;
			N--;
		}
		else 
		{
			N -= 2;
			p1++;
			p2--;
			k++;
		}
		
	}

return k;
}
int main()
{
	int a[6] = { 1,2,3,4,5,6 };
	int maxweight = 7;
	int b = minboat(6, a, maxweight);
	printf("所需船的最少数量为：");
	printf("%d", b);
}
