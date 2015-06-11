# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} head
# @return {ListNode}

def merge_list(l1, l2)
    head = ListNode.new(0)
    head.next = l1
    p1, p2 = head, l2
    # p p1, p2
    while p1.next && p2
        # puts "#{p1.next} #{p2}"
        if p1.next.val > p2.val
            q = p2.next
            p2.next = p1.next
            p1.next = p2
            p1 = p2
            p2 = q
            # puts "#{p1.next} #{p2}"
            # p p1, p2
        else
            p1 = p1.next
        end
    end

    if p2
        p1.next = p2
    end
    
    return head.next
end

def sort_list(head)
    if head == nil || head.next == nil
        return head
    end
    
    fast, slow = head, head
    while fast.next && fast.next.next
        fast = fast.next.next
        slow = slow.next
    end

    l2 = sort_list(slow.next)
    slow.next = nil
    l1 = sort_list(head)

    return merge_list(l1, l2)
end

# def list(nums)
#     head = ListNode.new(0)
#     p = head
#     for i in nums
#         p.next = ListNode.new(i)
#         p = p.next
#     end
#     return head.next
# end

# p sort_list(list([2, 1]))
# p sort_list(list([5, 4, 3, 8, 1]))
# p merge_list(list([1, 3]), list([2, 4, 5]))
