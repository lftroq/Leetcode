class Solution {
public:
    int cnt[100005];
    vector<int> sortArray(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++) cnt[nums[i]+50000]++;
        for(int i=0;i<=100000;i++) for(int j=0;j<cnt[i];j++) ans.push_back(i-50000);
        return ans;
    }
};