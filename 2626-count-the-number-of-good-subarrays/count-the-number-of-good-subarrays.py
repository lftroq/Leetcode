class Solution:
    def countGood(self, nums: List[int], k: int) -> int:
        n = len(nums)
        cn = {}
        j, cnt, ans = 0, 0, n * (n + 1) // 2
        for i in range(n):
            temp = cn[nums[i]] if nums[i] in cn else 0
            cnt += temp
            cn.update({nums[i]: temp + 1})
            while(cnt >= k):
                temp = cn[nums[j]] - 1
                cn.update({nums[j]: temp})
                cnt -= temp
                j += 1
            ans -= i - j + 1
        return ans