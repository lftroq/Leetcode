class Solution:
    def findLHS(self, nums: List[int]) -> int:
        nums.sort()
        j, ans = 0, 0
        for i in range(len(nums)):
            while(nums[i] - nums[j] > 1): j += 1
            if(nums[i] > nums[j]): ans = max(ans, i - j + 1)
        return ans