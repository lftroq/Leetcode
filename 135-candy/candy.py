class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        peak = [0] * n
        peak[0] = peak[n - 1] = 1
        cur = 1
        for i in range(1, n):
            cur = cur + 1 if ratings[i] > ratings[i - 1] else 1
            peak[i] = max(peak[i], cur)
        ans = peak[n - 1]
        for i in range(n - 2, -1, -1):
            cur = cur + 1 if ratings[i] > ratings[i + 1] else 1
            ans += max(cur, peak[i])
        return ans
