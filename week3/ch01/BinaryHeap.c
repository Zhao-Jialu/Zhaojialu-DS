#include<stdio.h>

struct HeapStruct {
	int Capacity;
	int Size;
	int* Elements;
};
typedef struct HeapStruct* Heap;
Heap Initialize(int maxsize) {
	Heap H;
	H = (Heap)malloc(sizeof(struct HeapStruct));
	H->Elements = malloc((maxsize + 1) * sizeof(int));
	H->Capacity = maxsize;
	H->Elements[0] = 0;
	H->Size = 0;
}
void Insert(Heap H, int x) {
	int i;
	for (i = ++H->Size; H->Elements[i / 2] > x; i = i / 2) {
		H->Elements[i] = H->Elements[i / 2];
	}
	H->Elements[i] = x;
}
int DeleteMin(Heap H) {
	int i, child;
	int min, last;
	if (H->Size == 0) {
		return H->Elements[0];
	}
	min = H->Elements[1];
	last = H->Elements[H->Size--];
	for (i = 1; 2*i <= H->Size; i = child) {
		child = 2 * i;
		if (child != H->Size && H->Elements[child + 1] < H->Elements[child]) {
			child++;
		}
		if (last > H->Elements[child]) 
			H->Elements[i] = H->Elements[child];
		else 
			break;
	}
	H->Elements[i] = last;
	return min;
}
void DecreaseKey(int n, int x, Heap H) {
	if (n > H->Size) {
		printf("超出队列的大小");
		return;
	}
	if(H->Elements[n]>=x){
		H->Elements[n] = H->Elements[n] - x;
	}
	int i;
	for (i = n; H->Elements[i / 2] > H->Elements[i]; i = i / 2) {
		int temp = H->Elements[i];
		H->Elements[i] = H->Elements[i / 2];
		H->Elements[i / 2] = temp;
	}
}

void IncreaseKey(int n, int x, Heap H) {
	if (n > H->Size) {
		printf("超出队列的大小");
		return;
	}
	H->Elements[n] = H->Elements[n] + x;
	int i,child;
	for (i = n; 2 * i <= H->Size; i = child) {
		child = 2 * i;
		if (child != H->Size && H->Elements[child + 1] < H->Elements[child]) {
			child++;
		}
		if (H->Elements[i] > H->Elements[child]) {
			int temp = H->Elements[i];
			H->Elements[i] = H->Elements[child];
			H->Elements[child] = temp;
		}
		else {
			break;
		}
	}
}
