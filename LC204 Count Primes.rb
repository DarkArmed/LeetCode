# @param {Integer} n
# @return {Integer}
def count_primes(n)
    if n < 3 then
        return 0
    end
    
    c = Math.sqrt(n)
    b = []
    count = 1
    
    3.step(c.to_i, 2) do |i|
        if !b[i] then
            (i * i).step(n, i << 1) do |j|
                b[j] = true
            end
        end
    end
    
    3.step(n - 1, 2) do |i|
        if !b[i] then
            count += 1
        end
    end

    return count
end

p count_primes(ARGV[0].to_i)