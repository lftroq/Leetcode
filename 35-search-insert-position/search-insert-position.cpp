class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        #define ll long long
        #define INFINITE 2147483647
        nums.push_back(INFINITE);
        ll temp=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        return temp;
    }
};