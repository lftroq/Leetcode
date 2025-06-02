class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums.sort()
        n = len(nums)
        j, k = n - 1, n - 1
        ans = 0
        lower -= 1
        print(nums)
        for i in range(0, n):
            while j > i and nums[j] + nums[i] > upper:
                j -= 1
            if i < j:
                ans += j - i
            while(k > i and nums[k] + nums[i] > lower):
                k -= 1
            if i < k:
                ans -= k - i
        return ans