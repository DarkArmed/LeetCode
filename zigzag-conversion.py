class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        
        sub = [''] * numRows

        cycle = max(numRows * 2 - 2, 1)
        i = 0
        for c in s:
            if i < numRows:
                sub[i] += c
            else:
                sub[cycle - i] += c
            i = (i + 1) % cycle
        
        return ''.join(sub)


# print Solution().convert('A', 1)
# print Solution().convert("PAYPALISHIRING", 3)