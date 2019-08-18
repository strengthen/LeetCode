__________________________________________________________________________________________________
sample 628 ms submission
"""
# Definition for a Node.
class Node:
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""

from collections import deque


class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if root is None:
            return []
        
        res = []
        q = deque([root])
        
        while q:
            lenq = len(q)
            level = []
            
            for _ in range(lenq):
                node = q.popleft()
                level.append(node.val)
                
                if len(node.children) > 0:
                    q += node.children
                    
            res.append(level[:])
            
        return res
__________________________________________________________________________________________________
sample 17468 kb submission

"""
# Definition for a Node.
class Node:
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        # if not root:
        #     return []
        # q = collections.deque()
        # q.append(root)
        # retlist = []
        # while q:
        #     q_len = len(q)
        #     levellist = []
        #     for i in range(q_len):
        #         node = q.popleft()
        #         levellist.append(node.val)
        #         for child in node.children:
        #             q.append(child)
        #     retlist.append(levellist)
        # return retlist
        if not root:
            return []
        res = []
        stack = [root]
        while stack:
            temp = []
            next_stack = []
            for node in stack:
                temp.append(node.val)
                for child in node.children:
                    next_stack.append(child)
            stack = next_stack
            res.append(temp)
        return res
__________________________________________________________________________________________________
