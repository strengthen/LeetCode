__________________________________________________________________________________________________
sample 20 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
import collections
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        res = []
        if not root:
            return res
        dq = collections.deque([root])
        
        while dq:
            for _ in range(len(dq)):
                node = dq.popleft()
                if node.left:
                    dq.append(node.left)
                if node.right:
                    dq.append(node.right)
            res.append(node.val)
        return res

__________________________________________________________________________________________________
sample 13012 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
import collections
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        # BFS and get the last element for each depth
        if not root:
            return []
        bfs_order = collections.deque([root])
        res = []
        while bfs_order:
            new_order = collections.deque([])
            while bfs_order:
                node = bfs_order.popleft()
                if node.left: 
                    new_order.append(node.left)
                if node.right:
                    new_order.append(node.right)
            res.append(node.val)
            bfs_order = new_order
        return res      
__________________________________________________________________________________________________
