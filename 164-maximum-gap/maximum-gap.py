class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        # There is n-1 gap between n numbers
        # Their total difference is maxVal - minVal
        # Therefore, there exist a gap whichs is >= (maxVal - minVal) / (n-1)
        # Divide into (n-1) equal segment
        n, minVal, maxVal = len(nums), min(nums), max(nums)
        if (n <= 2) or (maxVal == minVal):
            return maxVal - minVal
        gap = max(1, (maxVal - minVal) // (n - 1))
        buckets = [[None, None] for _ in range((maxVal - minVal) // gap + 1)]

        for num in nums:
            idx = (num - minVal) // gap
            if buckets[idx][0] == None:
                buckets[idx][0] = buckets[idx][1] = num
            else:
                buckets[idx][0] = min(buckets[idx][0], num)
                buckets[idx][1] = max(buckets[idx][1], num)

        ans = 0
        prev = minVal

        for bucket in buckets:
            if bucket[0] != None:
                ans = max(ans, bucket[0] - prev)
                prev = bucket[1]

        return ans
