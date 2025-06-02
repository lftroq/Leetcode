class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bool dp[20005] = {0};
        dp[0] = 1;
        int sum = 0;
        for(int i = 0; i < (int)nums.size(); i++) sum += nums[i];
        if(sum & 1) return false;
        cout << sum << endl;
        sum /= 2;
        for(int i = 0; i < (int)nums.size(); i++)
        {
            for(int j = sum; j >= nums[i]; j--) dp[j] |= dp[j - nums[i]];
        }
        cout << sum << endl;
        return dp[sum];
    }
};