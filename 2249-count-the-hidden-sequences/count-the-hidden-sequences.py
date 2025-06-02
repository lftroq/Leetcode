class Solution:
    def numberOfArrays(self, differences: List[int], lower: int, upper: int) -> int:
        ma, mi, s = 0, 0, 0
        for x in differences:
            s += x
            ma = max(ma, s)
            mi = min(mi, s)
        print(mi, ma)
        return max(0, upper - ma - lower + mi + 1)