class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans=-1,mi=1e9;
        for(int i=0;i<(int)nums.size();i++)
        {
            mi=min(mi,nums[i]);
            if(mi<nums[i]) ans=max(ans,nums[i]-mi);
        }
        return ans;
    }
};