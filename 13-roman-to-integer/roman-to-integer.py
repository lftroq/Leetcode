class Solution:
    def romanToInt(self, s: str) -> int:
        ans = 0
        n = len(s)
        i = 0
        while(i < n):
            if(s[i] == 'I'):
                if(i+1 < n and s[i+1] == 'V'): 
                    ans += 4
                    i += 1
                elif(i+1 < n and s[i+1] == 'X'):
                    ans += 9
                    i += 1
                else: ans += 1
            elif(s[i] == 'X'):
                if(i+1 < n and s[i+1] == 'L'): 
                    ans += 40
                    i += 1
                elif(i+1 < n and s[i+1] == 'C'):
                    ans += 90
                    i += 1
                else: ans += 10
            elif(s[i] == 'C'):
                if(i+1 < n and s[i+1] == 'D'): 
                    ans += 400
                    i += 1
                elif(i+1 < n and s[i+1] == 'M'):
                    ans += 900
                    i += 1
                else: ans += 100
            elif(s[i] == 'V'):
                ans += 5
            elif(s[i] == 'L'): 
                ans += 50
            elif(s[i] == 'D'):
                ans += 500
            elif(s[i] == 'M'): 
                ans += 1000
            i += 1
        return ans
