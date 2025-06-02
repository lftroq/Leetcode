class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        cn = [0 for _ in range(100)]
        ans = 0
        for x in dominoes:
            if x[0] > x[1]:
                x[0], x[1] = x[1], x[0]
            ans += cn[x[0] * 10 + x[1]]
            cn[x[0] * 10 + x[1]] += 1
        return ans