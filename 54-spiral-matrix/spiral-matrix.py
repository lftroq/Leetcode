class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        top, right, bot, left = 0, len(matrix[0]) - 1, len(matrix) - 1, 0
        ans = []
        cn = (right + 1) * (bot + 1)
        while(len(ans) < cn):
            for i in range(left, right + 1):
                ans.append(matrix[top][i])
            top += 1
            if(len(ans) == cn):
                return ans
            for i in range(top, bot + 1):
                ans.append(matrix[i][right])
            right -= 1
            if(len(ans) == cn):
                return ans
            for i in range(right, left - 1, -1):
                ans.append(matrix[bot][i])
            bot -= 1
            if(len(ans) == cn):
                return ans
            for i in range(bot, top - 1, -1):
                ans.append(matrix[i][left])
            left += 1
        return ans            
