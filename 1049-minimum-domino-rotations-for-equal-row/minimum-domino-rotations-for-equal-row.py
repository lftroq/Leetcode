class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        n = len(tops)
        def check(x: int) -> int:
            ansTop, ansBot = 0, 0
            for i in range(n):
                if tops[i] != x and bottoms[i] != x:
                    return 1000000000
                elif tops[i] == x and bottoms[i] != x:
                    ansBot += 1
                elif bottoms[i] == x and tops[i] != x:
                    ansTop += 1
            return min(ansTop, ansBot)
        print(check(2))
        ans = min(check(x) for x in range(1,7))
        if ans == 1000000000:
            ans = -1
        return ans