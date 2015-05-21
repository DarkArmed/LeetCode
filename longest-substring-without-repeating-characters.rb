# @param {String} s
# @return {Integer}
def length_of_longest_substring(s)
    ans, head = 0, 0
    map = Hash.new()
    for i in 0..s.length-1
        if !map[s[i]] || map[s[i]] < head
            ans = [ans, i - head + 1].max
        else
            head = map[s[i]] + 1
        end
        
        map[s[i]] = i
    end
    
    return ans
end