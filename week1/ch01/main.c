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
	struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));
	newNode->Data = data;
	newNode->Next = NULL;
	return newNode;
}
void insert(struct Node* headNode,int data)    //头插法
{
	struct Node* newNode= createNode(data);
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

int main()
{
	struct Node* List = createList();
	insert(List, 1);
	insert(List, 2);
	insert(List, 3);
	printList(List);
	delete(List, 2);
	printList(List);
	delete(List, 2);

}
