class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        n = len(gas)
        a = gas.copy()
        a[0] -= cost[0]
        for i in range(1, n):
            a[i] += a[i - 1] - cost[i]
        minVal = min(a)
        maxVal = max(a)
        if(maxVal < 0 or sum(gas) < sum(cost)):
            return -1
        for i in range(n):
            if(a[i] == minVal): 
                return (i + 1) % n