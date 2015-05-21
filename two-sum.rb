# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def two_sum(nums, target)
  h = Hash.new()
  i = 0
  nums.each do |n|
    if h[target - n] != nil then
      return [h[target - n] + 1, i + 1]
    end
    h[n] = i
    i += 1
  end
end

# p two_sum([2, 7, 11, 15], 9)
# p two_sum([2, 7, 11, 15], 13)
# p two_sum([2, 7, 11, 15], 17)
# p two_sum([2, 7, 11, 15], 22)
# p two_sum([2, 7, 11, 15], 26)
# p two_sum([0, 7, 11, 0], 0)
