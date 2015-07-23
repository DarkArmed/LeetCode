class Solution:
    # @param {integer[][]} matrix
    # @param {integer} target
    # @return {boolean}
    def searchMatrix(self, matrix, target):
        lx = ly = 0
        rx, ry = len(matrix) - 1, len(matrix[0]) - 1
        
        while lx <= rx and ly <= ry:
            if lx == rx and ly == ry:
                return matrix[lx][ly] == target
            
            l, r = lx, rx
            while l < r:
                m = (l + r + 1) / 2
                if matrix[m][ly] == target:
                    return True
                elif matrix[m][ly] < target:
                    l = m
                else:
                    r = m - 1
            rx = r
            
            l, r = lx, rx
            while l < r:
                m = (l + r) / 2
                if matrix[m][ry] == target:
                    return True
                elif matrix[m][ry] < target:
                    l = m + 1
                else:
                    r = m
            lx = l
            
            l, r = ly, ry
            while l < r:
                m = (l + r + 1) / 2
                if matrix[lx][m] == target:
                    return True
                elif matrix[lx][m] < target:
                    l = m
                else:
                    r = m - 1
            ry = r
            
            l, r = ly, ry
            while l < r:
                m = (l + r) / 2
                if matrix[rx][m] == target:
                    return True
                elif matrix[rx][m] < target:
                    l = m + 1
                else:
                    r = m
            ly = l
            
        else:
            return False
                    
# matrix = [
#             [1,   4,  7, 11, 15],
#             [2,   5,  8, 12, 19],
#             [3,   6,  9, 16, 22],
#             [10, 13, 14, 17, 24],
#             [18, 21, 23, 26, 30]
#          ]

# import sys
# print Solution().searchMatrix(matrix, int(sys.argv[1]))

# print Solution().searchMatrix([[1]], -1)


# for i in range(1, 40):
#     print i, Solution().searchMatrix(matrix, i)
