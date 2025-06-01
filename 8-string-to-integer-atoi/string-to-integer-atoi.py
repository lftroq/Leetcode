class Solution:
    def myAtoi(self, s: str) -> int:
        while len(s) and s[0] == ' ':
            s = s[1::]
        if len(s) == 0 or not(s[0].isdigit() or s[0] == '-' or s[0] == '+'):
            return 0
        am = False
        if s[0] == '-':
            am = True
            s = s[1::]
        elif s[0] == '+': s = s[1::]
        ans = 0
        while len(s) and s[0].isdigit():
            ans = ans * 10 + int(s[0])
            s = s[1::]
        if am: ans = -ans
        return max(-2 ** 31, min(2 ** 31 - 1, ans))