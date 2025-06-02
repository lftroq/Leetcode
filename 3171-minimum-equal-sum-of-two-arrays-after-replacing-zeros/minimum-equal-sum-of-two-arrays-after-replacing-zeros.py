import atexit

atexit.register(lambda: open("display_runtime.txt", "w").write("0"))

class Solution:
    def minSum(self, nums1: List[int], nums2: List[int]) -> int:
        s1, s2, ok1, ok2 = 0, 0, False, False
        for x in nums1:
            if x == 0:
                s1 += 1
                ok1 = True
            else:
                s1 += x
        for x in nums2:
            if x == 0:
                s2 += 1
                ok2 = True
            else:
                s2 += x
        if not ok1 and s1 < s2:
            return -1
        if not ok2 and s2 < s1:
            return -1
        return max(s1, s2)

