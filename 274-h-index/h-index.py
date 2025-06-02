class Solution:
    def hIndex(self, citations: List[int]) -> int:
        cntLeThan = [0] * 1002
        maxVal = 0
        for x in citations: 
            cntLeThan[x] += 1
            maxVal = max(maxVal, x)
        for i in range(maxVal, -1, -1): 
            cntLeThan[i] += cntLeThan[i + 1]
        ans, l, r = 0, 0, 1001
        while(l <= r):
            mid = (l + r) // 2
            if(cntLeThan[mid] >= mid):
                ans = mid
                l = mid + 1
            else: r = mid - 1
        return ans