class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        ans = []
        for i in range(n):
            if(i and nums[i] == nums[i - 1]):
                continue
            k = n - 1
            for j in range(i + 1, n):
                while(k - 1 > j and nums[i] + nums[j] + nums[k] > 0):
                    k -= 1
                if(j > i + 1 and nums[j] == nums[j - 1]):
                    continue
                if(k <= j):
                    break
                if(nums[i] + nums[j] + nums[k] == 0):
                    ans.append([nums[i], nums[j], nums[k]])
        return ans

        