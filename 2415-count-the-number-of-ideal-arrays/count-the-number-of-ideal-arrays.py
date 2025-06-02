class Solution:
    def idealArrays(self, n: int, maxValue: int) -> int:
        MOD = 10 ** 9 + 7
        m = min(n, 14)
        dp = [[0 for _ in range(m + 1)] for _ in range(maxValue + 1)]
        for i in range(1, maxValue + 1):
            dp[i][1] = 1
            j = 2
            while(i * j <= maxValue):
                for k in range(1, m):
                    dp[i * j][k + 1] += dp[i][k]
                j += 1
        fact = [1 for _ in range(n)]
        for i in range(1, n):
            fact[i] = fact[i - 1] * i % MOD
        invfact = [1 for _ in range(n)]
        invfact[n - 1] = pow(fact[n - 1], MOD - 2, MOD)
        for i in range(n - 1, 0, -1):
            invfact[i - 1] = invfact[i] * i  % MOD
        ans = 0
        def Cnk(n, k) -> int:
            return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD
        for i in range(1, maxValue + 1):
            for k in range(1, m + 1):
                ans += dp[i][k] * Cnk(n - 1, k - 1) % MOD
                ans %= MOD
        return ans


