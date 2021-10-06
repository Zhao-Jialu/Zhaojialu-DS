#include<stdio.h>
#include<stdlib.h>
typedef struct Node* Create;
struct Node 
{
	int Coe;
	int Index;
	Create Next;
};
struct Node* createList()
{
	Create headNode = (Create)malloc(sizeof(struct Node));
	headNode->Next= NULL;
	return headNode;
}
struct Node* createNode(int data1, int data2)
{
	Create newNode = (Create)malloc(sizeof(struct Node));
	newNode->Coe = data1;
	newNode->Index = data2;
	newNode->Next = NULL;
	return newNode;
}
void insert(Create headNode,int data1,int data2)   //头插法
{
	Create pMove = createNode(data1, data2);
	pMove->Next = headNode->Next;
	headNode->Next = pMove;
}

int Max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int Min(int a, int b)
{
	if (a > b)
	{
		return b;
	}
	else
	{
		return a;
	}
}
struct Node* sum(Create L1, Create L2)
{
	Create L3 = createList();
	Create Tmpcell = L3;
	int tmp;
	L1 = L1->Next;
	L2 = L2->Next;
	while (1)
	{
		if (L1->Index == L2->Index)
		{
			insert(Tmpcell,L1->Coe+L2->Coe , L1->Index);
			L1 = L1->Next;
			L2 = L2->Next;
		}
		else if (L1->Index > L2->Index)
		{
			insert(Tmpcell, L1->Coe, L1->Index);
			L1 = L1->Next;
		}
		else
		{
			insert(Tmpcell, L2->Coe, L2->Index);
			L2 = L2->Next;
		}
		if (L1 == NULL)
		{
			tmp = 1;
			break;
		}
		else if (L2 == NULL)
		{
			tmp = 2;
			break;
		}
	}
	if (tmp == 1)
	{
		while (L2 != NULL)
		{
			insert(Tmpcell, L2->Coe, L2->Index);
			L2 = L2->Next;
		}
	}
	else if (tmp == 2)
	{
		while (L1 != NULL)
		{
			insert(Tmpcell, L1->Coe, L1->Index);
			L1 = L1->Next;
		}
	}
	return L3;
}
void printList(Create headNode)
{
	Create P = headNode->Next;
	while (P != NULL)
	{
		printf("%d", P->Coe);
		printf(",");
		printf("%d", P->Index);
		printf("\t");
		P = P->Next;

	}
	printf("\n");
}
int main()
{
	Create L1 = createList();
	Create L2 = createList();
	
	insert(L1, 1, 0);
	insert(L1, 2, 1);
	insert(L1, 3, 2);
	insert(L1, 3, 3);
	insert(L2, 3, 1);
	insert(L2, 3, 2);
	insert(L2, 5, 3);
	
	printList(L1);
	printList(L2);
	Create L3 = sum(L1, L2);
	printList(L3);
}
