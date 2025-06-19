class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=1;
        for(int i=0,j=0;i<(int)nums.size();i++)
        {
            if(nums[i]-nums[j]>k)
            {
                ans++;
                j=i;
            }
        }
        return ans;
    }
};