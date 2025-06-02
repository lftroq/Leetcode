class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        reverse(nums.begin(),nums.end());
        for(int i=0;i<k;i++) nums.push_back(nums[i]);
        reverse(nums.begin(),nums.end());
        while(k--) nums.pop_back();
    }
};