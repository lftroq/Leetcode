class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        ma = max(nums)
        j, temp, ans = 0, 0, 0
        for i in range(len(nums)):
            if nums[i] == ma:
                temp += 1
            while temp > k or nums[j] != ma:
                temp -= (nums[j] == ma)
                j += 1
            if temp >= k:
                ans += j + 1
        return ans