class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        return sum((1 - (len(str(x)) % 2)) for x in nums)