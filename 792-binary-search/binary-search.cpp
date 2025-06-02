class Solution {
public:
    int search(vector<int>& nums, int target) {
        #define ll long long
        #define INFINITE 2147483647
        nums.push_back(INFINITE);
        ll temp=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(nums[temp]==target) return temp; else return -1;
    }
};