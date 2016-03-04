class Solution:
    # @param {string} s
    # @return {string}
    def longestPalindrome(self, s):
        
        k = 0
        l = [1] * len(s)
        
        for i in range(1, len(s)):
            print i, l[i - 1], s[i - 1 - l[i - 1]], s[i]
            if i - l[i - 1] > 0 and s[i - 1 - l[i - 1]] == s[i]:
                l[i] = l[i - 1] + 2
            elif s[i] == s[i - 1]:
                l[i] = 2
                
            if l[i] > l[k]:
                k = i

        print l
        print k, l[k]
        return s[k - l[k] + 1:k + 1]

# print Solution().longestPalindrome('ccc')