class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(),queries.end(),[](const vector<int> &a,const vector<int> &b){return a[0]<b[0];});
        priority_queue<int> pq;
        vector<int> p(nums.size()+1,0);
        int op=0;
        for(int i=0,j=0;i<(int)nums.size();i++)
        {
            op+=p[i];
            while(j<(int)queries.size()&&queries[j][0]==i) pq.push(queries[j++][1]);
            while(op<nums[i]&&!pq.empty()&&pq.top()>=i)
            {
                op++;
                p[pq.top()+1]--;
                pq.pop();
            }
            if(op<nums[i]) return -1;
        }
        return(int)pq.size();
    }
};