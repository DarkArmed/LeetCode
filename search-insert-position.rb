# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer}
def search_insert(nums, target)
    l, r = 0, nums.length
    while l < r
        m = (l + r) / 2
        if nums[m] < target
            l = m + 1
        elsif nums[m] > target
            r = m
        else
            return m
        end
    end
    
    return l
end

# p search_insert([0], 0)
# p search_insert([0], 1)
# p search_insert([0, 1], 3)
# p search_insert([1, 3, 5, 7, 9], 6)
# p search_insert([1, 3, 5, 7, 9, 11], 12)
