class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = {}
        for i in range(len(strs)):
            hsh = 0
            for x in strs[i]:
                hsh += 1000 ** (ord(x) - 97)
            if hsh not in mp:
                mp.update({hsh: [i]})
            else:
                mp[hsh].append(i)
        ans = []
        for x in mp.values():
            temp = []
            for y in x:
                temp.append(strs[y])
            ans.append(temp)
        return ans