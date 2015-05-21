# @param {Integer} n
# @param {Integer} k
# @return {Integer[][]}
def combine(n, k)
    if k == 0
        return [[]]
    elsif n == k
        return [Array(1..n)]
    else
        return combine(n - 1, k) + combine(n - 1, k - 1).map { |a| a << n}
    end
end

# p combine(0, 0)
# p combine(1, 1)
# p combine(2, 4)
# p combine(5, 3)
