class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n = len(nums)
        ans = n + 1
        j, s = 0, 0
        for i in range(n):
            s += nums[i]
            while(s - nums[j] >= target):
                s -= nums[j]
                j += 1
            if(s >= target):
                ans = min(ans, i - j + 1)
        if ans == n + 1:
            ans = 0
        return ans
