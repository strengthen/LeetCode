__________________________________________________________________________________________________
sample 24 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
def sum_root_to_leaf_number(root):
    def tree_sum(node, val):
        if not node:
            return 0
        val = 10*val + node.val
        if not node.left and not node.right:
            return val
        return tree_sum(node.left, val) + tree_sum(node.right, val)
    
    return tree_sum(root, 0)

class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        return sum_root_to_leaf_number(root)
__________________________________________________________________________________________________
sample 12944 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        
        def generator(node):
            if node is None:
                pass
            elif node.left is None and node.right is None:
                yield str(node.val)
            else:
                for number in generator(node.left):
                    yield str(node.val) + number
                for number in generator(node.right):
                    yield str(node.val) + number
                    
        s = 0
        for number_string in generator(root):
            s += int(number_string)
            
        return s
__________________________________________________________________________________________________
