class Solution {
public:
const int MOD=1e9+7;
    int dp[1001][1<<5][1<<5];
    bool check[1<<5][1<<5];
    int colorTheGrid(int m, int n) {
        int ans=0;
        for(int mask=0;mask<(1<<m);mask++)
        {
            for(int mask1=mask;;mask1=(mask&(mask1-1)))
            {
                check[mask][mask1]=1;
                int pr=(mask&1) + (mask1&1);
                for(int i=1;i<m;i++) 
                {
                    int c=(mask>>i&1)+(mask1>>i&1);
                    check[mask][mask1]&=(c!=pr);
                    pr=c;
                }
                if(!check[mask][mask1]) 
                {
                    if(!mask1) break;
                    continue;
                }
                if(n==1) ans++;
                dp[1][mask][mask1]=1;
                if(!mask1) break;
            }
        }
        for(int i=2;i<=n;i++) 
        {
            for(int mask=0;mask<(1<<m);mask++) for(int sub=mask;;sub=(mask&(sub-1)))
            {
                if(!check[mask][sub]) 
                {
                    if(!sub) break;
                    continue;
                }
                for(int mask1=0;mask1<(1<<m);mask1++) for(int sub1=mask1;;sub1=(mask1&(sub1-1)))
                {
                    if(!check[mask1][sub1])
                    {
                        if(!sub1) break;
                        continue;
                    }
                    bool ok=1;
                    for(int j=0;j<m;j++)
                    {
                        int c=(mask>>j&1)+(sub>>j&1);
                        int c1=(mask1>>j&1)+(sub1>>j&1);
                        ok&=(c!=c1);
                    }
                    if(!ok)
                    {
                        if(!sub1) break;
                        continue;
                    }
                    // cout << mask << ' ' << sub << "   " << mask1 << ' ' << sub1 << ' ' << dp[i-1][mask1][sub1] << endl;
                    (dp[i][mask][sub]+=dp[i-1][mask1][sub1])%=MOD;
                    if(!sub1) break;
                }
                // cout << i << ": " << mask << ' ' << sub << ' ' << dp[i][mask][sub] << endl;
                if(i==n) (ans+=dp[i][mask][sub])%=MOD;
                if(!sub) break;
            }
        }
        return ans;
    }
};