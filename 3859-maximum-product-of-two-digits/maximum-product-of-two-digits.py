class Solution:
    def maxProduct(self, n: int) -> int:
        ma1, ma2 = -1, -1
        for x in str(n):
            d = int(x)
            if ma1 < d:
                ma2 = ma1
                ma1 = d
            else:
                ma2 = max(ma2, d)
        return ma1 * ma2
            