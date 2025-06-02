class Solution:
    def reverseWords(self, s: str) -> str:
        lst = s.split(' ')[::-1]
        ans = ''
        for st in lst:
            ok = 0
            for c in st:
                if(c != ' '):
                    ans += c
                    ok = 1
            if(ok):
                ans += ' '
        return ans[:-1]
        