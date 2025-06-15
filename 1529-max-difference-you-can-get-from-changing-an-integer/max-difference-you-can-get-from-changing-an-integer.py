class Solution:
    def maxDiff(self, num: int) -> int:
        ma, mi = 0, int(1e9)
        for x, y in itertools.product([_ for _ in range(10)], repeat = 2):
            temp, ans, p = num, 0, 1
            while(temp):
                ans += (y if (temp % 10 == x) else temp % 10) * p
                p *= 10
                temp //= 10
            if(len(str(ans)) != len(str(num))):
                continue
            if(ans):
                ma = max(ma, ans)
                mi = min(mi, ans)
        return ma - mi