class Solution {
public:
    int MOD = 1e9 + 7;
    long long binpow(long long a, long long b)
    {
        long long ans = 1;
        while(b)
        {
            if(b & 1) (ans *= a) %= MOD;
            (a *= a) %= MOD;
            b >>= 1;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        return binpow(4, n/2) * binpow(5, n - n/2) % MOD;
    }
};