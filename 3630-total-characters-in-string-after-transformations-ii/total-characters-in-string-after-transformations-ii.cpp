class Solution {
public:
    const int MOD=1e9+7;
    typedef long long ll;
    vector<vector<ll>> mul(vector<vector<ll>> &a,vector<vector<ll>> &b)
    {
        assert(a[0].size()==b.size());
        vector<vector<ll>> c((int)a.size(),vector<ll>((int)b[0].size(),0));
        for(int i=0;i<(int)a.size();i++) for(int j=0;j<(int)b[0].size();j++)
        {
            for(int k=0;k<(int)a[0].size();k++) (c[i][j]+=(a[i][k]*b[k][j])%MOD)%=MOD;
        }
        return c;
    }
    vector<vector<ll>> po(vector<vector<ll>> a,ll b)
    {
        vector<vector<ll>> ans((int)a.size(),vector<ll>(a[0].size(),0));
        for(int i=0;i<(int)a.size();i++) ans[i][i]=1;
        while(b)
        {
            if(b&1) ans=mul(ans,a);
            a=mul(a,a);
            b>>=1;
        }
        return ans;
    }
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        vector<vector<ll>> base(26, vector<ll>(26,0));
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<nums[i];j++) base[i][(i+j+1)%26]++;
        }
        base=po(base,t);
        vector<vector<ll>> dp(1,vector<ll>(26,0));
        for(int i=0;i<(int)s.size();i++) dp[0][s[i]-'a']++;
        dp=mul(dp,base);
        int ans=0;
        for(int i=0;i<(int)dp[0].size();i++) (ans+=dp[0][i])%=MOD;
        return ans;
    }
};