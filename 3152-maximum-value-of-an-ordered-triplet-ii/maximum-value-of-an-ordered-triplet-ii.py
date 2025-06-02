class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        n = len(nums)
        ma = [0] * n
        ma[n - 1] = nums[n - 1]
        for i in range(n - 2, -1, -1):
            ma[i] = max(nums[i], ma[i + 1])
        mx = 0
        ans = 0
        for i in range(0, n):
            if(0 < i and i+1 < n): 
                ans = max(ans, (mx - nums[i]) * ma[i + 1])
                # print(mx, nums[i], ma[i + 1])
            mx = max(mx, nums[i])
        return ans