# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} l1
# @param {ListNode} l2
# @return {ListNode}
def add_two_numbers(l1, l2)
    sum = ListNode.new(l1.val + l2.val)
    l, l1, l2 = sum, l1.next, l2.next
    while l1 || l2 || l.val > 9
        l.next = ListNode.new(l.val / 10)
        l.val %= 10
        l = l.next
        
        if l1
            l.val += l1.val
            l1 = l1.next
        end
        
        if l2
            l.val += l2.val
            l2 = l2.next
        end
    end
    
    return sum
end