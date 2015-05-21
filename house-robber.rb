# @param {Integer[]} nums
# @return {Integer}
def rob(nums)
  l = nums.length
  
  case l
  when 0
    return 0
  when 1
    return nums[0]
  when 2
    return nums[0..1].max
  end
  
  nums[2] += nums[0]

  for i in 3..l-1
    nums[i] += nums[i-3, 2].max
  end

  return nums[l - 2, 2].max
end

# nums = []
# ARGV.each do |s|
#   nums.push s.to_i
# end

# p rob(nums)