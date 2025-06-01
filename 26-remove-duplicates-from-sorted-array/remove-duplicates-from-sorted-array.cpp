class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i = 1; i < (int)nums.size(); i++) if(nums[i] != nums[i-1]) ans.push_back(nums[i]);
        swap(ans,nums);
        return (int)nums.size();
    }
};