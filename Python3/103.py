__________________________________________________________________________________________________
sample 20 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        
        reverse = False
        que = deque([root])
        res = []
        while que:
            length = len(que)
            level = []
            for i in range(length):
                cur = que.popleft()
                level.append(cur.val)
                if cur.left:
                    que.append(cur.left)
                if cur.right:
                    que.append(cur.right)
                    
            if reverse:
                res.append(level[::-1])
            else:
                res.append(level)
                
            reverse = not reverse
        return res
__________________________________________________________________________________________________
sample 13224 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque


class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        
        res = []
        queue = deque([root])
        is_reverse = False
        
        while queue:
            res.append([])
            level_size = len(queue)
            
            for _ in range(level_size):
                node = queue.popleft()
                res[-1].append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            
            if is_reverse:
                res[-1].reverse()
            is_reverse = not is_reverse
        
        return res
__________________________________________________________________________________________________
