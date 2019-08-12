__________________________________________________________________________________________________
sample 48 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import collections

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        def helper(in_left = 0, in_right = len(inorder)):
            nonlocal pre_idx
            # if there is no elements to construct subtrees
            if in_left == in_right:
                return None
            
            # pick up pre_idx element as a root
            root_val = preorder[pre_idx]
            root = TreeNode(root_val)

            # root splits inorder list
            # into left and right subtrees
            index = idx_map[root_val]

            # recursion 
            pre_idx += 1
            # build left subtree
            root.left = helper(in_left, index)
            # build right subtree
            root.right = helper(index + 1, in_right)
            return root
        
        # start from first preorder element
        pre_idx = 0
        # build a hashmap value -> its index
        idx_map = {val:idx for idx, val in enumerate(inorder)} 
        return helper()        
__________________________________________________________________________________________________
sample 13992 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if not preorder or not inorder:
            return None
        
        j = 0
        root = TreeNode(preorder.pop(0))
        stack = [root]
        
        for i in preorder:
            parent = stack[-1]
            is_left = True
            node = TreeNode(i)
            
            while stack and inorder[j] == stack[-1].val:
                parent = stack.pop()
                is_left = False
                j += 1
                
            if is_left:
                parent.left = node
            else:
                parent.right = node
            
            stack.append(node)
            
        return root
    
    def bar():
        root = TreeNode(preorder.pop(0))
        stack = [root]
        # queue = [root]
        for i in preorder:
            parent = stack[-1]
            node = TreeNode(i)
            
    def foo():
        if not preorder or not inorder:
            return
        root = TreeNode(preorder.pop(0))
        index = inorder.index(root.val)
        
        root.left = self.buildTree(preorder, inorder[:index])
        
        root.right = self.buildTree(preorder, inorder[index+1:])
        return root
__________________________________________________________________________________________________
