class Solution {
public:
    const int MOD=1e9+7;
    long long fact[100001];
    long long binpow(long long a, long long b) {
        long long ans=1;
        while(b)
        {
            if(b&1) (ans*=a)%=MOD;
            (a*=a)%=MOD;
            b>>=1;
        }
        return ans;
    }
    int C(int k,int n) {
        return fact[n]*binpow(fact[k]*fact[n-k]%MOD,MOD-2)%MOD;
    }
    int countGoodArrays(int n, int m, int k) {
        fact[0]=1;
        for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i%MOD;
        return 1ll*m*binpow(m-1,n-1-k)%MOD*C(k,n-1)%MOD;
    }
};