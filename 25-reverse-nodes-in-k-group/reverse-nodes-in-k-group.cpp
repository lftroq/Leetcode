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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ans=new ListNode(0);
        ListNode* p=ans;
        while(head)
        {
            vector<int> v;
            for(int i=0;i<k;i++)
            {
                v.push_back(head->val);
                head=head->next;
                if(head==nullptr) break;
            }
            if(v.size()==k) for(int i=0;i<k;i++)
            {
                p->next=new ListNode(v.back());
                p=p->next;
                v.pop_back();
            }
            else for(int i=0;i<(int)v.size();i++)
            {
                p->next=new ListNode(v[i]);
                p=p->next;
            }
        }
        return ans->next;
    }
};