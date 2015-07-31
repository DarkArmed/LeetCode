class Solution:
    # @param {integer[]} nums1
    # @param {integer[]} nums2
    # @return {float}
    
    def findKth(self, a, b, k):
        
        m, n = len(a), len(b)
        
        if m > n:
            return self.findKth(b, a, k)
        
        if m == 0:
            return b[k - 1]
        
        if k == 1:
            return min(a[0], b[0])
        
        pa = min(k / 2, m)
        pb = k - pa
        
        if a[pa - 1] < b[pb - 1]:
            return self.findKth(a[pa:], b, k - pa)
        elif a[pa - 1] > b[pb - 1]:
            return self.findKth(a, b[pb:], k - pb)
        else:
            return a[pa - 1]
    
    def findMedianSortedArrays(self, nums1, nums2):
        
        total = len(nums1) + len(nums2)
        
        if total & 1:
            return self.findKth(nums1, nums2, total / 2 + 1)
        else:
            return (self.findKth(nums1, nums2, total / 2) + self.findKth(nums1, nums2, total / 2 + 1)) / 2.0