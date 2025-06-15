class Solution {
public:
    typedef long long ll;
    const int MOD=1e9+7;
    ll C[31][31],dp[52][51][51][51];
    ll binpow(ll a,ll b)
    {
        ll ans=1;
        while(b)
        {
            if(b&1) (ans*=a)%=MOD;
            (a*=a)%=MOD;
            b>>=1;
        }
        return ans;
    }
    int magicalSum(int M, int K, vector<int>& nums) {
        C[0][0]=1;
        for(int i=1;i<=M;i++)
        {
            C[i][0]=1;
            for(int j=1;j<=M;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
        }
        int n=(int)nums.size();
        for(int u=0;u<=M;u++) dp[0][u][u&1][u>>1]=binpow(nums[0],u);
        for(int i=1;i<n;i++) for(int x=0;x<=M;x++)
        {
            for(int k=0;k<=K;k++) for(int s=0;s<(1<<5);s++)
            {
                if(!dp[i-1][x][k][s]) continue;
                //cout << i-1 << ' ' << x << ' ' << k << ' ' << s << ": " << dp[i-1][x][k][s] << endl;
                // dont take nums[i]
                //(dp[i][x][k+(s&1)][s>>1]+=dp[i-1][x][k][s])%=MOD;
                // take y nums[i]
                for(int y=0;x+y<=M;y++)
                {
                    int t=s+y;
                    (dp[i][x+y][k+(t&1)][t>>1]+=dp[i-1][x][k][s]*binpow(nums[i],y)%MOD*C[x+y][y]%MOD)%=MOD;
                }
            }
        }
        //cout << "===" << endl;
        ll ans=0;
        for(int k=0;k<=K;k++) for(int s=0;s<(1<<5);s++) 
        {
            if(k+__builtin_popcount(s)==K) 
            {
                //cout << n-1 << ' ' << M << ' ' << k << ' ' << s << ": " << dp[n-1][M][k][s] << endl;
                (ans+=dp[n-1][M][k][s])%=MOD;
            }
        }
        return ans;
    }
};