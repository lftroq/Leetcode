class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> ms;
        vector<int> ans;
        for(int i=0;i<k-1;i++) ms.insert(nums[i]);
        for(int i=k-1;i<nums.size();i++)
        {
            if(ms.size()>=k) ms.erase(ms.find(nums[i-k]));
            ms.insert(nums[i]);
            ans.push_back(*ms.rbegin());
        }
        return ans;
    }
};