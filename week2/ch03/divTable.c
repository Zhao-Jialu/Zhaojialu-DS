#include <stdio.h>
#include<stdlib.h>
typedef struct ListNode* Position;
struct ListNode {
	int data;
	Position Next;
};
typedef Position List;
typedef struct HashTbl* HashTable;
struct HashTbl {
	int TableSize;
	List* TheLists;
};
int Hash(int Key, int TableSize) {        //知道Key所对应的数组单元
	return Key % TableSize;
}
HashTable createTable(int TableSize) {    //初始化
	HashTable H;
	int i;
	H = (HashTable)malloc(sizeof(struct HashTbl));
	if (H == NULL) {
		printf("Out of sapce!!!");
	}
	H->TableSize = TableSize;
	H->TheLists = (List*)malloc(sizeof(List) *H->TableSize);//动态申请指向头指针的指针的空间
	for (i = 0; i < H->TableSize; i++) {
		H->TheLists[i] = (Position)malloc(sizeof(struct ListNode));//动态申请头指针的空间
		H->TheLists[i]->Next = NULL;
	}
}
Position Find(int Key, HashTable H) {     //查找
	Position P;
	List L;
	L = H->TheLists[Hash(Key, H->TableSize)];
	P = L->Next;
	while(P != NULL&&P->data!=Key) {
		P = P->Next;
	}
	return P;
}

void insert(int Key, HashTable H) {     //插入
	Position Pos, Newcell;
	List L;
	Pos = Find(Key, H);
	if (Pos == NULL)
	{	
		Newcell= (Position)malloc(sizeof(struct ListNode));
		L= H->TheLists[Hash(Key, H->TableSize)];
		Newcell->Next = L->Next;
		Newcell->data = Key;
		L->Next = Newcell;
	}
}

