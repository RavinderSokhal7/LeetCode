/*
Reorder List
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
You may not modify the values in the list's nodes, only nodes itself may be changed.
Example 1:
Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:
Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
*/
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
    public void reorderList(ListNode head) {
        if(head==null || head.next==null) return;
        ListNode mid = head, p = head;
        while(p!=null && p.next!=null){
            mid = mid.next;
            p = p.next.next;
        }
        Stack<ListNode> s = new Stack<>();
        p = mid;
        while(p!=null){
            s.push(p);p = p.next;
        }
        ListNode q = null, r = null;
        p = head;
        while(!s.isEmpty()){
            q = s.pop();
            if(s.isEmpty()) break;
            r = s.peek();
            r.next = null;
            q.next = p.next;
            p.next = q;
            p = p.next.next;
        }
    }
}
