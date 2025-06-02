class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        dx = [-1, -1, -1, 0, 0, 1, 1, 1]
        dy = [-1, 0, 1, -1, 1, -1, 0, 1]
        n, m = len(board), len(board[0])
        newBoard = [[0 for _ in range(m)] for _ in range(n)]
        for i in range(n):
            for j in range(m):
                cn = 0
                for k in range(8):
                    x, y = i + dx[k], j + dy[k]
                    if (0 <= x < n) and (0 <= y < m):
                        cn += board[x][y]
                if board[i][j]:
                    if(2 <= cn <= 3):
                        newBoard[i][j] = 1
                else:
                    if(cn == 3):
                        newBoard[i][j] = 1
        for i in range(n):
            for j in range(m):
                board[i][j] = newBoard[i][j]
        """
        Do not return anything, modify board in-place instead.
        """
        