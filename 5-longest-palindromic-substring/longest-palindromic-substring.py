class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        dp = [[False for _ in range(n)] for _ in range(n)]
        ansl, ansr = 0, 0
        for length in range(0, n):
            for l in range(0, n - length):
                r = l + length
                if r - l <= 1: 
                    dp[l][r] = (s[l] == s[r])
                elif s[l] == s[r]:
                    dp[l][r] = dp[l + 1][r - 1]
                if(dp[l][r]):
                    ansl, ansr = l, r
        return s[ansl: ansr + 1]