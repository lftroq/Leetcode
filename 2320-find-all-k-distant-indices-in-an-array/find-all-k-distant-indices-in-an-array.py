class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        n = len(nums)
        ans = []
        for i in range(n):
            ok = False
            for j in range(max(0, i - k), min(n, i + k + 1)):
                ok |= (nums[j] == key)
            if(ok): ans.append(i)
        return ans