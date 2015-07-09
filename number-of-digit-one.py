class Solution:
    # @param {integer} n
    # @return {integer}
    def countDigitOne(self, n):
        count, tail, x = 0, 0, 1
        
        while n > 0:
            if n % 10 > 0:
                if n % 10 > 1:
                    count += x
                else:
                    count += tail + 1

            tail += n % 10 * x
            n /= 10
            count += n * x
            x *= 10

        return count

# s = Solution()
# print s.countDigitOne(13)
# print s.countDigitOne(169)
# print s.countDigitOne(2147483647)