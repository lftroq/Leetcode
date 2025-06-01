class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cn[20005]={0};
        vector<int> ans;
        for(int i=0;i<(int)nums.size();i++) 
        {
            if(cn[nums[i]+10000]<=1) ans.push_back(nums[i]),cn[nums[i]+10000]++;
        }
        swap(ans,nums);
        return (int)nums.size();
    }
};