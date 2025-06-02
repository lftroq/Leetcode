class Solution:
    def countLargestGroup(self, n: int) -> int:
        def calc(x: int) -> int:
            ans = 0
            while(x):
                ans += x % 10
                x //= 10
            return ans
        cn = [0 for _ in range(100)]
        for i in range(1, n + 1):
            cn[calc(i)] += 1
        ma = max(cn)
        ans = 0
        for x in cn:
            if ma == x:
                ans += 1
        return ans