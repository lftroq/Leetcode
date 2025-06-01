class Solution:
    def reverse(self, x: int) -> int:
        ans = str(x)[::-1]
        if ans[-1] == '-':
            ans = ans[-1:] + ans[:-1]
        ans = int(ans)
        return ans if -2**31 <= ans <= 2**31 - 1 else 0