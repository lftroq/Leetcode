class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        suffix = [0] * (len(nums) + 1)
        suffix[len(nums)] = 1
        for i in range(len(nums) - 1, -1, -1):
            suffix[i] = suffix[i + 1] * nums[i]
        cur = 1
        ans = []
        for i in range(len(nums)):
            ans.append(cur * suffix[i + 1])
            cur *= nums[i]
        return ans
        