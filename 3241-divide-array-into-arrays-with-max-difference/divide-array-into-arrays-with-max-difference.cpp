class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        for(int i=2;i<(int)nums.size();i+=3) if(nums[i]-nums[i-2]>k) return {};
        vector<vector<int>> ans;
        for(int i=0;i<(int)nums.size();i+=3) ans.push_back({nums[i],nums[i+1],nums[i+2]});
        return ans;
    }
};