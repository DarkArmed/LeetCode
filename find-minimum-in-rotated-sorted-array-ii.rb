# @param {Integer[]} nums
# @return {Integer}
def find_min(nums)
    l = nums.length
    m = l / 2
    if l == 1 || nums[0] < nums[l - 1]
        return nums[0]
    elsif l == 2
        return nums[1]
    elsif nums[m] < nums[0]
        return find_min(nums[1, m])
    elsif nums[m] > nums[0] || nums[m] > nums[l - 1] || nums[m] > nums[m + 1]
        return find_min(nums[m + 1..l])
    else
        return find_min(nums[1..l - 2])
    end
end