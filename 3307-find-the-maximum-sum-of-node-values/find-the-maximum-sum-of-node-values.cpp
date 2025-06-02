class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long s =0;
        vector<long long> ans;
        for(int i=0;i<(int)nums.size();i++)
        {
            int x=nums[i];
            s+=x;
            ans.push_back((x^k)-x);
        }
        sort(ans.begin(),ans.end(),greater<int>());
        for(int i=0;i+1<(int)ans.size();i+=2)
        {
            if(ans[i]+ans[i+1]<=0) break;
            s+=ans[i]+ans[i+1];
        }
        return s;
    }
};