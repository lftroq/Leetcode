class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums = set(nums)
        mp = {}
        ans = 0
        for num in nums:
            x = mp.get(num - 1, 0)
            y = mp.get(num + 1, 0)
            val = x + y + 1
            mp[num - x] = mp[num + y] = val
            ans = max(ans, val)
        return ans