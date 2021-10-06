#include<stdio.h>
#include<stdlib.h>
struct Node
{
	struct Node* Next;
	int Data;
};
struct Node* createList()   //链表初始化
{
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	headNode->Next = NULL;
	return headNode;
}
struct Node* createNode(int data)  //创建新的节点
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->Data = data;
	newNode->Next = NULL;
	return newNode;
}
void insert(struct Node* headNode, int data)    //头插法
{
	struct Node* newNode = createNode(data);
	newNode->Next = headNode->Next;
	headNode->Next = newNode;
}
void delete(struct Node* headNode, int data) //按数值删除
{
	struct Node* p = headNode->Next;
	struct Node* p2 = headNode;
	if (p2->Next == NULL)
	{
		printf("无法删除，该链表为空链表。\n");
	}
	else
	{
		while (p->Data != data)
		{
			p2 = p;
			p = p->Next;
			if (p == NULL)
			{
				printf("没有找到相关信息，无法删除。\n");
				return;
			}
		}
		p2->Next = p->Next;
		free(p);
	}
}

void printList(struct Node* headNode)
{
	struct Node* p = headNode->Next;
	while (p != NULL)
	{
		printf("%d\t", p->Data);
		p = p->Next;
	}
	printf("\n");
}

struct Node* and (struct Node* L1, struct Node* L2)  //交集
{
	struct Node* L3 = createList();
	struct Node* Tmpcell;
	struct Node* Tmp;
	Tmpcell = L3;
	int tmp;
	L1 = L1->Next;
	while (L1!= NULL) 
	{
		tmp = L1->Data;
		L1 = L1->Next;
		Tmp = L2->Next;
		while (Tmp != NULL)
		{
			
			if (Tmp->Data == tmp)
			{
				
				insert(Tmpcell, tmp);
				
			}
			Tmp = Tmp->Next;
		}
	}
	return L3;
}
struct Node* or (struct Node* L1, struct Node* L2) //并集
{
	struct Node* L3 = createList();
	struct Node* Tmpcell;
	struct Node* Tmp;
	struct Node* Tmp2;
	struct Node* Tmp3;
	struct Node* Tmp4;
	Tmpcell = L3;
	int tmp;
	Tmp2 = L1->Next;
	Tmp3 = L2->Next;
	Tmp4 = L2->Next;
	while (Tmp2 != NULL) 
	{
		insert(Tmpcell, Tmp2->Data);
		Tmp2 = Tmp2->Next;

	}
	while (Tmp4 != NULL)
	{
		tmp = Tmp4->Data;
		Tmp4 = Tmp4->Next;
		Tmp = L1->Next;
		while (Tmp != NULL)
		{

			if (Tmp->Data == tmp)
			{

				delete(L2,tmp);
				
			}
			Tmp = Tmp->Next;
		}
	}
	while (Tmp3 != NULL)
	{
		insert(Tmpcell, Tmp3->Data);
		Tmp3 = Tmp3->Next;

	}
	return L3;
}

int main()
{
	struct Node* L1 = createList();
	struct Node* L2 = createList();
	insert(L1, 1);
	insert(L1, 5);
	insert(L1, 4);
	insert(L2, 1);
	insert(L2, 2);
	insert(L2, 3);
	struct Node* L3 = and (L1, L2);
	printf("交集为:");
	printList(L3);
	L3 = or (L1, L2);
	printf("并集为：");
	printList(L3);
	return 0;
}
