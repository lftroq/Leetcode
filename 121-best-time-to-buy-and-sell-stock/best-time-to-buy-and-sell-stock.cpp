class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,mi=1e4;
        for(int i=0;i<(int)prices.size();i++)
        {
            mi=min(mi,prices[i]);
            ans=max(ans,prices[i]-mi);
        }
        return ans;
    }
};