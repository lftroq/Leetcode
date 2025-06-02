class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        idxminK, idxmaxK, idxwr, ans = -1, -1, -1, 0
        for i in range(len(nums)):
            if nums[i] == minK:
                idxminK = i
            if nums[i] == maxK:
                idxmaxK = i
            if nums[i] < minK or nums[i] > maxK:
                idxwr = i
            ans += max(0, min(idxminK, idxmaxK) - idxwr)
        return ans