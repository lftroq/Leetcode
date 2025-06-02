class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        k = 0
        for x in t:
            if k < len(s) and x == s[k]:
                k += 1
        return k == len(s)
        