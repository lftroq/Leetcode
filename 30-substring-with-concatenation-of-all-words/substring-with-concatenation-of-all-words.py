class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        n = len(s)
        total_len = len(words) * len(words[0])
        word_len = len(words[0])
        ans = []
        word_count = defaultdict(int)
        for word in words:
            word_count[word] += 1
        for i in range(n - total_len + 1):
            cur_count = word_count.copy()
            ok = True
            for j in range(i, i + total_len, word_len):
                if ok == False:
                    break
                w = s[j: j + word_len]
                if w in cur_count:
                    cur_count[w] -= 1
                    if(cur_count[w] == -1):
                        ok = False
                        break
                else:
                    ok = False
                    break
            if(ok):
                ans.append(i)
        return ans