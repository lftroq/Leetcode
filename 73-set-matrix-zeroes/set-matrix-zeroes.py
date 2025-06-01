class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        n, m = len(matrix), len(matrix[0])
        row, col = [0 for _ in range(n)], [0 for _ in range(m)]
        for i, j in itertools.product([x for x in range(n)], [y for y in range(m)]):
            if not matrix[i][j]:
                row[i] = 1
                col[j] = 1
        for i in range(n):
            if(row[i]):
                for j in range(m): 
                    matrix[i][j] = 0
        for j in range(m):
            if(col[j]):
                for i in range(n):
                    matrix[i][j] = 0
        """
        Do not return anything, modify matrix in-place instead.
        """
        