class Solution:
    def countAndSay(self, n: int) -> str:
        if(n == 1):
            return "1"
        s = self.countAndSay(n - 1)
        cur = s[0]
        cn = 1
        ans = ""
        for x in s[1:]:
            if(cur == x):
                cn += 1
            else:
                ans += str(cn) + cur
                cur = x
                cn = 1
        ans += str(cn) + cur
        return ans
        
