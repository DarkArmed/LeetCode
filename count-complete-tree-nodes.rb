# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} root
# @return {Integer}

def tree_height(root)
    h = 0
    p = root
    while p
        p = p.left
        h = h + 1
    end
    return h
end

def count_nodes(root)
    if root == nil
        return 0
    elsif root.right == nil
        if root.left == nil
            return 1
        else
            return 2
        end
    end
    
    h = tree_height(root)
    
    rh = tree_height(root.right)
    
    if rh == h - 1
        return 2 ** (h - 1) + count_nodes(root.right)
    else
        return count_nodes(root.left) + 2 ** rh
    end
end