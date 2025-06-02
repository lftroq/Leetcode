class Solution:
    def countGoodIntegers(self, n: int, k: int) -> int:
        fact = [1 for _ in range(n + 1)]
        for i in range(1, n + 1): 
            fact[i] = fact[i - 1] * i 
        def calc(a: list[int]) -> int:
            s = sum(a)
            ans = fact[s]
            for x in a:
                ans //= fact[x]
            return ans
        ans = 0
        validPalindrome = []

        for x in range(10 ** ((n + 1) // 2 - 1), 10 ** ((n + 1) // 2)):
            pal = x
            st = str(x)[::-1]
            while(len(st) < (n + 1) // 2): st.append('0')
            pal = (str(pal)[:-1:] if n % 2 == 1 else str(pal)) + st
            if(int(pal) % k == 0):
                lst = [0 for _ in range(10)]
                for x in pal:
                    lst[int(x)] += 1
                num = []
                for d in range(10):
                    for i in range(lst[d]): num.append(str(d))
                validPalindrome.append(''.join(num))

        validPalindrome = list(set(validPalindrome))
        for pal in validPalindrome:
            lst = [0 for _ in range(10)]
            for x in pal:
                lst[int(x)] += 1
            ans += calc(lst)
            if(lst[0]):
                lst[0] -= 1
                ans -= calc(lst)
        print(validPalindrome)
        return ans
