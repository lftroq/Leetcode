class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        return sum(1 for i, j, k in itertools.combinations(arr, r = 3) if abs(i - j) <= a and abs(j - k) <= b and abs(i - k) <= c)