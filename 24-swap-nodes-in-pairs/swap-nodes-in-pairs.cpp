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
    ListNode* swapPairs(ListNode* head) {
        ListNode* ans=new ListNode(0);
        ListNode* p=ans;
        while(head)
        {
            ListNode* cur=head;
            head=head->next;
            if(head==nullptr)
            {
                p->next=new ListNode(cur->val);
                break;
            }
            ListNode* cur2=head;
            head=head->next;
            p->next=new ListNode(cur2->val);
            p=p->next;
            p->next=new ListNode(cur->val);
            p=p->next;
        }
        return ans->next;
    }
};