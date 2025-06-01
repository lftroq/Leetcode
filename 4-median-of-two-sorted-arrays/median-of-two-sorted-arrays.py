class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1
        n, m = len(nums1), len(nums2)
        if not (n + m):
            return 0
        toGet = (n + m + 1) // 2
        l, r = 0, min(toGet, n)
        while l <= r:
            mid1 = (l + r) // 2
            mid2 = toGet - mid1
            # get mid item in the left
            if mid2 > m:
                l = mid1 + 1
                continue

            maxLeft1, maxLeft2, minRight1, minRight2 = -1e9, -1e9, 1e9, 1e9
            if mid1:
                maxLeft1 = max(maxLeft1, nums1[mid1 - 1])
            if mid2:
                maxLeft2 = max(maxLeft2, nums2[mid2 - 1])
            if mid1 < n:
                minRight1 = min(minRight1, nums1[mid1])
            if mid2 < m:
                minRight2 = min(minRight2, nums2[mid2])
            # print(l, r, ':', mid)
            maxLeft = max(maxLeft1, maxLeft2)
            minRight = min(minRight1, minRight2)
            # print(maxLeft1, maxLeft2, minRight1, minRight2)
            if maxLeft <= minRight:
                if (n + m) % 2 == 1:
                    return maxLeft
                else:
                    return (maxLeft + minRight) / 2
            elif maxLeft1 > maxLeft2:
                r = mid1 - 1
            else:
                l = mid1 + 1
        return -1e9 