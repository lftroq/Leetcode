class Solution {
public:
    int dp[51][11][11];
    int minTravelTime(int l, int n, int k, vector<int>& position, vector<int>& time) {
        vector<int> ptime=time;
        for(int i=0;i+1<n;i++) ptime[i+1]+=ptime[i];
        for(int i=0;i<n;i++) for(int j=0;j<=k;j++) for(int r=0;r<=k;r++) dp[i][j][r]=1e9;
        dp[0][0][0]=0;
        for(int cn=0;cn<=k;cn++)
        {
            for(int i=1;i<n;i++)
            {
                for(int j=i-1;j>=0;j--)
                {
                    int c=i-j-1;
                    if(c>cn) break;
                    for(int la=0;la<=cn;la++)
                    {
    //                    cout << ":::" << i << ' ' << j << ' ' << la << ' ' << dp[j][cn-c][la] << ' ' << position[i]-position[j] << ' ' << ptime[j] << ' ' << ptime[j-la-1] << endl;
                        if(j-la-1>=0) dp[i][cn][c]=min(dp[i][cn][c],dp[j][cn-c][la]+(position[i]-position[j])*(ptime[j]-ptime[j-la-1]));
                        else dp[i][cn][c]=min(dp[i][cn][c],dp[j][cn-c][la]+(position[i]-position[j])*ptime[j]);
    //                    cout << " ::" << i << ' ' << cn << ' ' << c << ": " << dp[i][cn][c] << endl;
                    }
                }
    //            for(int j=0;j<=cn;j++) cout << dp[i][cn][j] << ' ';
    //            cout << endl;
            }
    //        cout << endl;
    //        cout << "===" << endl;
        }
    //    for(int i=0;i<n;i++)
    //    {
    //        cout << i << ":" << endl;
    //        for(int j=0;j<=k;j++)
    //        {
    //            for(int l=0;l<=k;l++) cout << dp[i][j][l] << ' ';
    //            cout << endl;
    //        }
    //        cout << "===" << endl;
    //    }
        int ans=1e9;
        for(int j=0;j<=k;j++) ans=min(ans,dp[n-1][k][j]);
        return ans;
    }
};