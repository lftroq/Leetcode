class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        j = len(numbers) - 1
        for i in range(0, len(numbers)):
            while(j - 1 > i and numbers[i] + numbers[j] > target):
                j -= 1
            if(numbers[i] + numbers[j] == target):
                return [i + 1, j + 1]
            