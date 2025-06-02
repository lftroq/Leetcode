class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        n = len(dominoes)
        aR, aL = [-1 for _ in range(n + 1)], [n for _ in range(n + 1)]
        for i in range(n):
            aR[i] = aR[i - 1]
            if dominoes[i] == 'R': aR[i] = i
            elif dominoes[i] == 'L': aR[i] = -1
        for i in range(n - 1, -1, -1):
            aL[i] = aL[i + 1]
            if dominoes[i] == 'L': aL[i] = i
            elif dominoes[i] == 'R': aL[i] = n
        ans = ""
        for i in range(n):
            if dominoes[i] == '.':
                xR, xL = i - aR[i], aL[i] - i
                if aR[i] == -1: xR = 10 ** 9
                if aL[i] == n: xL = 10 ** 9
                if xL < xR: 
                    ans += 'L'
                elif xR < xL: 
                    ans += 'R'
                else:
                    ans += '.'
            else:
                ans += dominoes[i]
        return ans
            