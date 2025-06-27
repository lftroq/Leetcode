class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n=(int)s.size();
        int dp[1005]={0};
        for(int i=0;i<n;i++)
        {
            dp[i+1]=2e9;
            for(int j=i+1;j>=0;j--) dp[j+1]=min(dp[j+1],(int)min((long long)2e9,2ll*dp[j]+(s[i]-'0')));
            // for(int j=i+1;j>=0;j--) cout << j << ": " << dp[j] << endl;
            // cout << "===" << endl;
        }
        for(int i=n;i>=0;i--) if(dp[i]<=k) return i;
        return -1;
    }
};