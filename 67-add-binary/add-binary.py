class Solution:
    def addBinary(self, a: str, b: str) -> str:
        a = a[::-1]
        b = b[::-1]
        temp = 0
        ans = ""
        for i in range(max(len(a), len(b))):
            s = temp
            if(i < len(a)): s += int(a[i])
            if(i < len(b)): s += int(b[i])
            temp = s // 2
            s %= 2
            ans += str(s)
        if(temp): ans += '1'
        return ans[::-1]