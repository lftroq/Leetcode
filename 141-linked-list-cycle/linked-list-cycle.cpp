/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
        ListNode *hare=head->next;
        head=head->next;
        if(hare==NULL) return false;
        hare=hare->next;
        if(hare==NULL) return false;
        while(hare!=head)
        {
            head=head->next;
            hare=hare->next;
            if(head==NULL) return false;
            if(hare==NULL) return false;
            hare=hare->next;
            if(hare==NULL) return false;
        }
        return true;
    }
};