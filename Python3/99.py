__________________________________________________________________________________________________
sample 56 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    
    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        nodes = []
        vals = []
        self.helper(root, nodes, vals)
        vals.sort()
        l = len(vals)
        for i in range(l):
            if nodes[i].val != vals[i]:
                nodes[i].val = vals[i]
                
    def helper(self, root: TreeNode, nodes, vals) -> None: 
            if root != None: 
                self.helper(root.left, nodes, vals)
                nodes.append(root)
                vals.append(root.val)
                self.helper(root.right, nodes, vals)
                
__________________________________________________________________________________________________
sample 13160 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        stack = []
        last_node, node_a, node_b = None, None, None
        while stack or root:
            if root:
                stack.append(root)
                root = root.left
            else:
                root = stack.pop()                
                if last_node is not None and root.val < last_node.val:
                    if node_a is None:
                        node_a = last_node
                    node_b = root

                last_node = root
                root = root.right
        node_a.val, node_b.val = node_b.val, node_a.val
        return root
__________________________________________________________________________________________________
