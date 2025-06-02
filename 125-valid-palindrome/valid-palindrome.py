class Solution:
    def isPalindrome(self, s: str) -> bool:
        ans = "".join([char.lower() for char in s if char.isalnum()])
        return ans == ans[::-1]
