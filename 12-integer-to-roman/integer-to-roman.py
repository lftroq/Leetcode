class Solution:
    def intToRoman(self, num: int) -> str:
        value = [
            [1000, 'M'], [900, 'CM'], [500, 'D'], [400, 'CD'],
            [100, 'C'], [90, 'XC'], [50, 'L'], [40, 'XL'],
            [10, 'X'], [9, 'IX'], [5, 'V'], [4, 'IV'],
            [1, 'I']
        ]
        ans = ''
        for temp in value:
            val = temp[0]
            symbol = temp[1]
            while(num >= val):
                num -= val
                ans += symbol
        return ans