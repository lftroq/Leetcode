class Solution:
    def countPairs(self, nums: List[int], k: int) -> int:
        ans = 0
        temp = [x for x in range(0, len(nums))]
        for i, j in itertools.combinations(temp, r = 2): 
            ans += (nums[i] == nums[j] and i * j % k == 0)
        return ans