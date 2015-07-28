class Solution:
    # @param {integer} num
    # @return {string}
    def intToRoman(self, num):

        roman  = {1000: 'M', 900: 'CM', 500: 'D', 400: 'CD', 100: 'C', 90: 'XC', 50: 'L', 40: 'XL', 10: 'X', 9: 'IX', 5: 'V', 4: 'IV', 1: 'I'}

        s = ""

        for i in sorted(roman.keys(), reverse = True):
            while num >= i:
                s += roman[i]
                num -= i

        return s

# for num in range(4000):
#     print num, Solution().intToRoman(num)