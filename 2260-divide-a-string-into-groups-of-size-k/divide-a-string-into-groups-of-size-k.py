class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        ans = []
        for i in range(0, len(s), k):
            if(i + k - 1 < len(s)):
                ans.append(s[i:i+k])
            else:
                temp = s[i:i+k]
                temp += (k - len(temp)) * fill
                ans.append(temp)
        return ans
        