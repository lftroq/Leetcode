class Solution:
    def findClosest(self, x: int, y: int, z: int) -> int:
        temp = abs(x - z) - abs(y - z)
        return 1 if temp < 0 else (2 if temp > 0 else 0)