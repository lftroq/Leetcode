class Solution:
    def countSymmetricIntegers(self, low: int, high: int) -> int:
        ans = 0
        for i in range(0, 100):
            for j in range(0, 100 if i > 9 else 10):
                if(i <= 9): 
                    temp = i * 10 + j
                else:
                    temp = i * 100 + j
                if temp < low or temp > high:
                    continue
                if sum(int(x) for x in str(i)) == sum(int(x) for x in str(j)):
                    ans += 1
        return ans
