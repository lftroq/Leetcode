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
        if(head==NULL) return head;
        while(head->next!=NULL&&head->next->val==val)
        {
            head->next=head->next->next;
        }
        if(head->next!=NULL) removeElements(head->next,val);
        if(head->val==val) return head->next;
        return head;
    }
};