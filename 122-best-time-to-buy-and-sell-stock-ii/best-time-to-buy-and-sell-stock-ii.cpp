class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp[30000];
        dp[0] = 0;
        for(int i = 1, ma = -prices[0]; i < (int)prices.size(); i++)
        {
            dp[i] = max(dp[i-1], ma + prices[i]);
            ma = max(ma, dp[i] - prices[i]);
        }
        return dp[(int)prices.size()-1];
    }
};