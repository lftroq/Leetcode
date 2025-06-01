class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        prefixMax, suffixMax = [0] * n, [0] * n
        prefixMax[0] = height[0]
        for i in range(1, n):
            prefixMax[i] = max(prefixMax[i - 1], height[i])
        suffixMax[n - 1] = height[n - 1]
        for i in range(n - 2, -1, -1):
            suffixMax[i] = max(suffixMax[i + 1], height[i])
        ans = 0
        for i in range(1, n - 1):
            ans += max(0, min(prefixMax[i - 1], suffixMax[i + 1]) - height[i])
        return ans
