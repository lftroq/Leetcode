class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        cnt = [0 for _ in range(2001)]
        target = len(set(nums))
        j = 0
        ans = len(nums) * (len(nums) + 1) // 2
        for i in range(len(nums)):
            cnt[nums[i]] += 1
            if cnt[nums[i]] == 1:
                target -= 1
            while target == 0:
                cnt[nums[j]] -= 1
                if cnt[nums[j]] == 0:
                    target += 1
                j += 1
            ans -= i - j + 1
        return ans
