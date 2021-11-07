#include<stdio.h>
int Average(int N, int a[]) {  //N为卡牌堆数，a为存放卡牌数量的数组
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += a[i];
	}
	
	int v = sum / N;   //v为平均值
	int count = 0;
	for (int i = 0; i < N; i++) {
		if (a[i] > v)//若a[i]大于v，则将多余的部分给他后面那个牌堆
		{
			a[i + 1] += a[i] - v; 
			a[i] = v;
			count++;
		}
		if (a[i] < v)//若a[i]小于v，则取后面牌堆上的牌来补充自己
		{
			
			a[i + 1] = a[i + 1] - (v - a[i]);
			a[i] = v;
				count++;
		}
	}
	return count;
}
int main() 
{
	int a[4] = { 9,8,17,6 };
	int b = Average(4, a);
	printf("需要移动的最小次数为：");
	printf("%d", b);
	return 0;

}
