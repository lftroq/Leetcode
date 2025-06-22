class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        temp = 1 if (dividend * divisor > 0) else -1
        return min(2 ** 31 - 1, max(-2 ** 31, abs(dividend) // abs(divisor) * temp))