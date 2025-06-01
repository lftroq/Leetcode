class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        n = len(strs)
        prefix = strs[0]
        for str in strs[1:]:
            while(not str.startswith(prefix)): 
                prefix = prefix[:-1]
                if(not prefix): break
            if(not prefix): break
        return prefix