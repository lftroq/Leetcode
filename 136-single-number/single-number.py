class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        cn = [0] * 60001
        v = []
        for x in nums:
            cn[x] ^= 1
            if(cn[x] == 1): 
                v.append(x)
        for x in v: 
            if(cn[x]): return x