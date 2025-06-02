class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        n = len(questions)
        dp = [0 for _ in range(n)]
        for i in range(n - 1, -1, -1):
            dp[i] = max(dp[i + 1] if i + 1 < n else 0, questions[i][0] + (dp[i + questions[i][1] + 1] if i + questions[i][1] + 1 < n else 0))
            print(i, ':', dp[i])
        return dp[0]