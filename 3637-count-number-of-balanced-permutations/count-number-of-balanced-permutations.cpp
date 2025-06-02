class Solution {
public:
    typedef long long ll;
    const int MOD=1000000007;
    int C[41][41];
    int c[10];
    int dp[41][721],dp1[41][721];
    int countBalancedPermutations(string num) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n=(int)num.size(),s=0,cnt=0;
        for(int i=0;i<n;i++) c[num[i]-'0']++;
        if((c[1]+c[3]+c[5]+c[7]+c[9])&1) return 0;
        C[0][0]=1;
        for(int i=1;i<=n-n/2;i++)
        {
            C[0][i]=1;
            for(int j=1;j<=i;j++) C[j][i]=(C[j-1][i-1]+C[j][i-1])%MOD;
        }
        dp[0][360]=1;
        for(int d=0;d<=9;d++)
        {
            if(!c[d]) continue;
            for(int i=0;i<=min(n/2,cnt);i++) 
            {
                int j=cnt-i;
                if(j>n-n/2) continue;
                for(int sum=max(0,360-s);sum<=min(720,360+s);sum++)
                {
                    if(!dp[i][sum]) continue;
                    for(int cn=0;cn<=c[d];cn++)
                    {
                        int pi=i+cn,pj=j+(c[d]-cn),ps=sum-cn*d+(c[d]-cn)*d;
                        if(pi>n/2||pj>n-n/2||ps>720||ps<0) continue;
                        dp1[pi][ps]+=1ll*dp[i][sum]*C[cn][pi]%MOD*C[c[d]-cn][pj]%MOD;
                        if(dp1[pi][ps]>MOD) dp1[pi][ps]-=MOD;
                    }
                }
            }
            s+=c[d]*d;
            cnt+=c[d];
            for(int i=0;i<=min(n/2,cnt);i++) 
            {
                int j=cnt-i;
                if(j>n-n/2) continue;
                for(int sum=max(0,360-s);sum<=min(720,360+s);sum++)
                {
                    dp[i][sum]=dp1[i][sum];
                    dp1[i][sum]=0;
                }
            }
        }
        return dp[n/2][360];
    }
};