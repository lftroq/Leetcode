class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        ans = ""
        temp = 1
        while(columnNumber):
            columnNumber -= 1
            x = columnNumber % 26
            ans += chr(x + 65)
            columnNumber //= 26
        return ans[::-1]
