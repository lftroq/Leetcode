class Solution:
    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        def calc(x: int) -> int:
            cnt = [0 for _ in range(len(nums) + 1)]
            print(cnt)
            ans = 0
            j = 0
            print(x)
            for i in range(len(nums)):
                cnt[nums[i]] += 1
                if cnt[nums[i]] == 1:
                    x -= 1
                while x == 0:
                    cnt[nums[j]] -= 1
                    if cnt[nums[j]] == 0:
                        x += 1
                    j += 1
                ans += j
                print(i, j)
            return ans
        return calc(k) - calc(k + 1)