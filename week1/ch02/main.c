#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int Data;
	struct Node* Next;
};
struct Node* createList()
{
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	headNode->Next = NULL;
	return headNode;
}
struct Node* createNode(int data) 
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->Data = data;
	newNode->Next = NULL;
	return newNode;
}
void insert(struct Node* headNode,int data)
{
	struct Node* pMove = createNode(data);
	pMove->Next = headNode->Next;
	headNode->Next = pMove;
}

void PrintLots(struct Node* L, struct Node* P)
{
	int temp,i;
	struct Node* pMove;
	while (P->Next != NULL)
	{
		P = P->Next;
		temp = P->Data;
		i = 0;
		pMove = L;
		while (i != temp)
		{
			pMove = pMove->Next;
			i++;
		}
		printf("%d\t", pMove->Data);
	}
}
void PrintList(struct Node* headNode)
{
	while (headNode->Next != NULL) 
	{
		headNode = headNode->Next;
		printf("%d\t", headNode->Data);
	}
	printf("\n");
}
int main()
{
	struct Node* L = createList();
	struct Node* P = createList();
	insert(L, 5);
	insert(L, 4);
	insert(L, 3);
	insert(L, 2);
	insert(L, 1);
	PrintList(L);
	insert(P, 5);
	insert(P, 3);
	insert(P, 1);
	PrintList(P);
	PrintLots(L, P);
	
}
