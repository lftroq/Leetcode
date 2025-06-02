class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        long long ans=0;
        for(int i=0;i<gifts.size();i++) pq.push(gifts[i]);
        for(int i=0;i<k;i++)
        {
            int temp=sqrt(pq.top());
            pq.pop();
            pq.push(temp);
        }
        while(pq.size())
        {
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};