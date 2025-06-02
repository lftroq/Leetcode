class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        cn = [0 for _ in range(1001)]
        ans = 0
        for x in answers:
            cn[x] += 1
        for i in range(1001):
            ans += ceil(cn[i] / (i + 1)) * (i + 1)
        return ans