class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums.sort()
        n = len(nums)
        ians = 0
        dp = [1] * n
        trace = [0] * n

        for i in range(0, n):
            for j in range(0, i): 
                if(nums[i] % nums[j] == 0): 
                    dp[i] = max(dp[i], dp[j] + 1)
                    if(dp[i] == dp[j] + 1): trace[i] = j + 1
            if(dp[i] > dp[ians]): ians = i

        ans = []
        while(ians != -1):
            ans.append(nums[ians])
            ians = trace[ians] - 1

        return ans
        