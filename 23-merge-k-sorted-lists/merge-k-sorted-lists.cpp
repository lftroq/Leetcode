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
    #define fi first
    #define se second
    #define pii pair<int,int>
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=(int)lists.size();
        bool ok=0;
        for(int i=0;i<k;i++) ok|=(lists[i]!=nullptr);
        if(!ok) return nullptr;
        ListNode *ans=new ListNode();
        ListNode *p=ans;
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        for(int i=0;i<k;i++) if(lists[i]!=nullptr) pq.push({lists[i]->val,i});
        pii temp=pq.top();
        pq.pop();
        p->val=temp.fi;
        lists[temp.se]=lists[temp.se]->next;
        if(lists[temp.se]!=nullptr) pq.push({lists[temp.se]->val,temp.se});
        while((int)pq.size())
        {
            pii temp=pq.top();
            pq.pop();
            p->next=new ListNode(temp.fi);
            p=p->next;
            lists[temp.se]=lists[temp.se]->next;
            if(lists[temp.se]!=nullptr) pq.push({lists[temp.se]->val,temp.se});
        }
        return ans;
    }
};