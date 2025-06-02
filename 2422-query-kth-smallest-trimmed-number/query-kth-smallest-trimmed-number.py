class Solution:
    def smallestTrimmedNumbers(self, nums: List[str], queries: List[List[int]]) -> List[int]:
        ask = [[] for _ in range(len(nums[0]))]
        ans = [0] * len(queries)
        for i in range(len(queries)):
            query = queries[i]
            ask[queries[i][1] - 1].append([queries[i][0], i])

        numArr = [0] * len(nums)
        idxArr = [0] * len(nums)
        for i in range(len(nums)):
            numArr[i] = int(nums[i])
            idxArr[i] = i
        radixArray = [[] for _ in range(10)]
        maxVal = max(numArr)
        exp = 1
        cur = 0
        while(maxVal):
            while(len(numArr) > 0):
                val = numArr.pop()
                idx = idxArr.pop()
                radixIdx = val % 10
                radixArray[radixIdx].append([val // 10, idx])
            for x in radixArray:
                while(len(x) > 0):
                    temp = x.pop()
                    numArr.append(temp[0])
                    idxArr.append(temp[1])

            for query in ask[cur]:
                ans[query[1]] = idxArr[query[0] - 1]
            maxVal //= 10
            cur += 1
        return ans
            