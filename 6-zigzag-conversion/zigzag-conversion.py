class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        n = len(s)
        ans = []
        for i in range(0, n, numRows * 2 - 2):
            ans.append(s[i])
        if numRows >= 3:
            pos = 1
            for dis in range(numRows * 2 - 4, 0, -2):
                for i in range(pos, n, numRows * 2 - 2):
                    ans.append(s[i])
                    if i + dis < n:
                        ans.append(s[i + dis])
                pos += 1
        for i in range(numRows - 1, n, numRows * 2 - 2):
            ans.append(s[i])
        return "".join(ans)
