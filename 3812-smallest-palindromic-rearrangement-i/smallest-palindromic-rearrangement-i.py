class Solution:
    def smallestPalindrome(self, s: str) -> str:
        c = [0 for _ in range(26)]
        for x in s:
            c[ord(x) - 97] += 1
        ans = []
        for x in range(26):
            while(c[x] > 1):
                ans.append(chr(x + 97))                
                c[x] -= 2
        for x in range(26):
            if(c[x]):
                ans.append(chr(x + 97))
                temp = ''.join(ans)
                return temp[:-1:] + temp[::-1]
        temp = ''.join(ans)
        return temp + temp[::-1]