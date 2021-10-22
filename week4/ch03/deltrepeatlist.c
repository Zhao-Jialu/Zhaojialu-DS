#include<stdio.h>
struct ListNode {
    int Data;
    struct ListNode* Next;
};
struct ListNode* createList()   //链表初始化
{
    struct ListNode* headNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    headNode->Next = NULL;
    return headNode;
}
struct ListNode* createNode(int data)  //创建新的节点
{
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->Data = data;
    newNode->Next = NULL;
    return newNode;
}
void insert(struct ListNode* headNode, int data)    //头插法
{
    struct ListNode* newNode = createNode(data);
    newNode->Next = headNode->Next;
    headNode->Next = newNode;
}
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL)
        return NULL;
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    fast = fast->Next;
    while (fast != NULL)
    {
        while (fast->Data == slow->Data)
        {
            slow->Next = fast->Next;
            fast = fast->Next;
            if (fast == NULL)
                return head;
        }
        slow = fast;
        fast = fast->Next;
    }
    return head;
}
void printList(struct ListNode* head) {
    struct ListNode* P = head;
    P = P->Next;
    while (P != NULL) {
        printf("%d\t", P->Data);
        P = P->Next;
    }
    printf("\n");
}
int main()
{
    struct ListNode* head = createList();
    insert(head, 1);
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 3);
    printList(head);
    head = deleteDuplicates(head);
    printList(head);

}
