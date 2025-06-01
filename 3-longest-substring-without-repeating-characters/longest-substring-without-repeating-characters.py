class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        j, ans = 0, 0
        cn = [0]*255
        for i in range(0, n):
            temp = ord(s[i])
            cn[temp] += 1
            while(j < i and cn[temp] > 1):
                cn[ord(s[j])] -= 1
                j += 1
            ans = max(ans, i - j + 1)
        return ans
        