__________________________________________________________________________________________________
sample 28 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isCompleteTree(self, root: TreeNode) -> bool:
        if not root:
            return True
        queue = [root]
        missing = False
        while queue:
            node = queue.pop(0)
            if node is None:
                missing = True
                continue
            if missing:
                return False
            queue.append(node.left)
            queue.append(node.right)
        return True
__________________________________________________________________________________________________
sample 13104 kb submission
# Time:  O(n)
# Space: O(w)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isCompleteTree(self, root):
        current = [root]
        end = False
        while current:
            next_level = []
            for node in current:
                if node is None:
                    end = True
                    continue
                if end:
                    return False
                next_level.append(node.left)
                next_level.append(node.right)
            current = next_level
        return True
__________________________________________________________________________________________________
