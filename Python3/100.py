__________________________________________________________________________________________________
sample 16 ms submission
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if not p and not q: return True
        if not (p and q): return False
        if p.val == q.val and self.isSameTree(p.left, q.left) and self.isSameTree(p.right,q.right): return True
        return False
__________________________________________________________________________________________________
sample 13004 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        queue = [(p, q)]
        while queue:
            node1, node2 = queue.pop(0)
            if not node1 and not node2:
                continue
            elif None in [node1, node2]:
                return False
            else:
                if node1.val != node2.val:
                    return False
                queue.append((node1.left, node2.left))
                queue.append((node1.right, node2.right))
        return True                
__________________________________________________________________________________________________
