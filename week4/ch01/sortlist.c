#include<stdio.h>
#include<stdlib.h>
typedef struct ListNode* ListNode;
struct ListNode {
	int val;
	ListNode next;
};
ListNode CreateNode(int x) {
	ListNode Node = (ListNode)malloc(sizeof(struct ListNode));
	Node->val = x;
	Node->next = NULL;
	return Node;
}
ListNode CreateList() {
	ListNode head= (ListNode)malloc(sizeof(struct ListNode));
	head->next = NULL;
	return head;
}
void insert(ListNode head, int x) {    //头插法
	ListNode newNode = CreateNode(x);
	newNode->next = head->next;
	head->next = newNode;
}
struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL)
        return NULL;
    struct ListNode* fast = head->next;   //fast指针用来遍历链表并与slow指针所指的数值进行比较
    struct ListNode* slow = head->next;   // slow指针，每次fast指针遍历一遍后，slow+1
    while (slow != NULL)
    {
        fast = slow;
        while (fast != NULL)
        {
            if (fast->val < slow->val)
            {
                int tmp = fast->val;
                fast->val = slow->val;
                slow->val = tmp;
            }
            fast = fast->next;
        }
        slow = slow->next;
    }
    return head;
}
void PrintList(ListNode head)
{
    ListNode a = head;
    a = a->next;
    while (a != NULL)
    {
        printf("%d\t", a->val);
        a = a->next;
    }
    printf("\n");
}
int main()
{
    ListNode a = CreateList();
    insert(a, 4);
    insert(a, 2);
    insert(a, 1);
    insert(a, 3);
    PrintList(a);
    a = sortList(a);
    PrintList(a);
}
