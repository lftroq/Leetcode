class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        cnt = len(words[0])
        lst = [words[0]]
        ans = []
        for word in words[1:]:
            if(cnt + len(word) + 1 <= maxWidth):
                cnt += len(word) + 1
                lst.append(word)
            else:
                st = lst[0]
                cnt -= len(lst) - 1
                spacesLeft = maxWidth - cnt
                if (len(lst) - 1 == 0):
                    st += ' ' * spacesLeft
                else:
                    padding = spacesLeft // (len(lst) - 1)
                    rem = spacesLeft % (len(lst) - 1)
                    for x in lst[1:]:
                        st += ' ' * (padding + (rem > 0))
                        rem -= 1
                        st += x
                ans.append(st)
                lst.clear()

                cnt = len(word)
                lst.append(word)

        st = ' '.join(lst)
        st += ' ' * (maxWidth - len(st))
        ans.append(st)

        return ans
