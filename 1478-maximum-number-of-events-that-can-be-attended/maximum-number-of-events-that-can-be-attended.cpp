class Solution {
public:
    vector<int> v[100005];
    int maxEvents(vector<vector<int>>& events) {
        for(int i=0;i<(int)events.size();i++)
        {
            int l=events[i][0],r=events[i][1];
            v[l].push_back(r);
        }
        priority_queue<int,vector<int>,greater<int>> pq;
        int ans=0;
        for(int i=1;i<=100000;i++)
        {
            while(v[i].size())
            {
                pq.push(v[i].back());
                v[i].pop_back();
            }
            while(pq.size()&&pq.top()<i) pq.pop();
            if(pq.size())
            {
                ans++;
                pq.pop();
            }
        }
        return ans;
    }
};