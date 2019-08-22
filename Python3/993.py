__________________________________________________________________________________________________
sample 20 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        if not root: return False
        siblings = cousin = False
        queue = collections.deque([root])
        queue1 = collections.deque()
        while queue and not cousin:
            while queue:
                node = queue.popleft()
                if not node: siblings = False
                else:
                    if node.val == x or node.val == y:
                        if not cousin: cousin = siblings = True
                        else: return not siblings
                    queue1.append(node.left)
                    queue1.append(node.right)
                    queue1.append(None)
            queue, queue1 = queue1, queue
        return False
__________________________________________________________________________________________________
sample 12992 kb submission
from collections import defaultdict, deque
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        d = dict()
        q = deque([(root,0,-1)])
        while q:
            r, l, p = q.popleft()
            d[r.val] =(l,p)
            if r.left:
                q.append((r.left, l+1,r.val))
            if r.right:
                q.append((r.right, l+1,r.val))
        return d[x][0] == d[y][0] and d[x][1] != d[y][1]
__________________________________________________________________________________________________
