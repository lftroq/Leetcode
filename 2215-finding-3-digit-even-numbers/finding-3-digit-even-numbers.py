class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        cn = [0 for _ in range(10)]
        for x in digits:
            cn[x] += 1
        ans = []
        for x in range(100, 1000, 2):
            c = [0 for _ in range(10)]
            ok = True
            t = x
            while(t):
                c[t % 10] += 1
                t //= 10
            for d in range(10):
                ok &= (c[d] <= cn[d])
            if(ok): 
                ans.append(x)
        return ans