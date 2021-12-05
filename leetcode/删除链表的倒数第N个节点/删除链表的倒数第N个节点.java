/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int len=0;
        ListNode p1=head;
        ListNode p2=head;
        ListNode p3=head.next;
        while(p1!=null){
            len++;
            p1=p1.next;
        }
        if(len==1)
        return null;
        if(n==len){
            head=head.next;
            return head;
        }
        for(int i=0;i<len-n-1;i++){
            p2=p2.next;
            p3=p3.next;
        }
        p2.next=p3.next;
        return head;
    }
}
