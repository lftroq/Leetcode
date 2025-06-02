class Solution:
    def numberOfPowerfulInt(self, start: int, finish: int, limit: int, s: str) -> int:
        suffixStart, suffixFinish, p10 = 0, 0, 1
        plim = [1] * 18
        start -= 1
        for x in range(1, 18):
            plim[x] = plim[x - 1] * (limit + 1)
        for x in range(len(s)):
            suffixStart = suffixStart + (start % 10) * p10
            start //= 10
            suffixFinish = suffixFinish + finish % 10 * p10
            finish //= 10
            p10 *= 10

        def calc(x: int, c: int, suffix: int) -> int:
            if x < 0:
                return 0
            ans = 0
            sn = str(x)
            for i in range(len(sn)):
                cur = int(sn[i])
                if cur > c:
                    ans += plim[len(sn) - i]
                    return ans
                else:
                    ans += plim[len(sn) - i - 1] * cur
            return ans + (suffix >= int(s))

        return calc(finish, limit, suffixFinish) - calc(start, limit, suffixStart)
