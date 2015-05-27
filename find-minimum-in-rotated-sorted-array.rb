# @param {Integer[]} nums
# @return {Integer}
def find_min(nums)
    l = nums.length
    m = l / 2
    if l == 1 || nums[0] < nums[l - 1]
        return nums[0]
    elsif nums[m] > nums[0]
        return find_min(nums[m + 1..l])
    else
        return find_min(nums[1, m])
    end
end