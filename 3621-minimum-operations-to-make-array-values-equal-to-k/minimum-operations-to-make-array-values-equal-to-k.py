class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        nums = list(dict.fromkeys(nums))
        nums.sort()
        if(nums[0] < k): return -1
        elif(nums[0] == k): return len(nums) - 1
        return len(nums)
        