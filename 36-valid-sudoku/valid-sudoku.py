class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for r in range(9):
            row = [x for x in board[r] if x != '.']
            if len(row) != len(set(row)):
                return False
        
        for c in range(9):
            col = [board[r][c] for r in range(9) if board[r][c] != '.']
            if len(col) != len(set(col)):
                return False
        
        for r, c in itertools.product(range(3), repeat = 2):
            rm, cm = r * 3, c * 3
            square = [board[rm + x][cm + y] for x, y in itertools.product(range(3), repeat = 2) if board[rm + x][cm + y] != '.']
            if len(square) != len(set(square)):
                return False
        
        return True