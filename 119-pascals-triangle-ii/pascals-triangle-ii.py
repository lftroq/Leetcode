class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        ans = [0] * (rowIndex + 1)
        ans[0] = 1
        for i in range(rowIndex):
            for j in range(i + 1, 0, -1):
                ans[j] += ans[j - 1]
        return ans