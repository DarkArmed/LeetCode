class Solution:
    # @param {integer[][]} matrix
    # @param {integer} target
    # @return {boolean}
    def searchMatrix(self, matrix, target):
        
        l, r = 0, len(matrix) - 1
        while l < r:
            m = (l + r + 1) / 2
            if matrix[m][0] > target:
                r = m - 1
            else:
                l = m
        t = l
        
        l, r = 0, len(matrix[t]) - 1
        while l <= r:
            m = (l + r) / 2
            if matrix[t][m] == target:
                return True
            elif matrix[t][m] < target:
                l = m + 1
            else:
                r = m - 1
        else:
            return False