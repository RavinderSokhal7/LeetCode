/*
 Remove Linked List Elements

Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5


*/
//Solution : time : O( n ) : space : O( 1 )
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* h = new ListNode();
        h->next = head;
        ListNode* p=h;
        while(p->next){
            if(p->next->val == val){
                ListNode* q = p->next;
                p->next=p->next->next;
                delete q;
            }
            else{
                p = p->next;
            }
        }
        return h->next;
    }
};
