class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> ans;
        for(int i = 0; i < (int)nums.size(); i++) if(nums[i] != val)
        {
            ans.push_back(nums[i]);
        }
        swap(ans,nums);
        return (int)nums.size();
    }
};