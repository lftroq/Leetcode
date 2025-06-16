class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans=-1;
        for(int i=0;i<(int)nums.size();i++) for(int j=0;j<i;j++)
        {
            if(nums[i]<=nums[j]) continue;
            ans=max(ans,nums[i]-nums[j]);
        }
        return ans;
    }
};