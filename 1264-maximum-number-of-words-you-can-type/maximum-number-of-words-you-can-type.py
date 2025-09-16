class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        words = text.split(' ')
        ans = 0
        for word in words:
            ok = 1
            for c in brokenLetters:
                if c in word:
                    ok = 0
            ans += ok
        return ans