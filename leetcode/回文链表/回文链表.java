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
    public boolean isPalindrome(ListNode head) {
        int[] arr = new int[100000];
        int index=0;
        ListNode tmp=head;
        while(tmp!=null){
            arr[index++]=tmp.val;
            tmp=tmp.next;
        }
        ListNode p=reverseList(head);
        int i=0;
        while(p!=null){
            if(p.val!=arr[i])
            return false;
            p=p.next;
            i++;
        }
        return true;
    }
        public ListNode reverseList(ListNode head) {
       return reverse(head,null);
        }
    private ListNode reverse(ListNode head,ListNode L){
        if(head==null)
        return L;
        ListNode p=head.next;
        head.next=L;
        return reverse(p,head);
    }
}
