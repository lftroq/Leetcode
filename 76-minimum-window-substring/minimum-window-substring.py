class Solution:
    def minWindow(self, s: str, t: str) -> str:
        cn = {}
        for x in t:
            if x not in cn:
                cn.update({x: 1})
            else: 
                cn[x] += 1
        cur = len(cn)
        for x in s:
            if x not in cn:
                cn.update({x: 0})
        j = 0
        ans = ''
        for i in range(len(s)):
            cn[s[i]] -= 1
            if(cn[s[i]] == 0):
                cur -= 1
            while j < i and cur == 0 and cn[s[j]] < 0:
                cn[s[j]] += 1
                j += 1
            if cur == 0:
                if len(ans) == 0 or len(ans) > len(s[j: i + 1]):
                    ans = s[j: i + 1]
        return ans
