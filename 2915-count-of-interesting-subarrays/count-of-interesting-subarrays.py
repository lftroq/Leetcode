class Solution:
    def countInterestingSubarrays(self, nums: List[int], modulo: int, k: int) -> int:
        cnt = [0 for _ in range(min(len(nums) + 1, modulo))]
        ans, s = 0, 0
        cnt[0] = 1
        for i in range(len(nums)):
            s += int(nums[i] % modulo == k)
            ans += cnt[(s - k + modulo * modulo) % modulo] if (s - k + modulo * modulo) % modulo < len(cnt) else 0
            cnt[s % modulo] += 1
        return ans