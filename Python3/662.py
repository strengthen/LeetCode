__________________________________________________________________________________________________
sample 28 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        if not root:
            return 0
        curr_d=res =first= 0
        curr = collections.deque([(root, 0, 0)])
        while curr:
            node, d, p = curr.popleft()
            if d != curr_d:
                first = p
                curr_d = d
            if node.left:
                curr.append((node.left, d+1, 2*p))
            if node.right:
                curr.append((node.right, d+1, 2*p+1))
            res = max(res, p-first+1)
        return res 
__________________________________________________________________________________________________
sample 13488 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        # using BFS with virtual index for calculation
        if not root: return 0
        q = collections.deque()
        q.append((root, 0))
        res =0
        while len(q):
            nx = collections.deque()
            res = max(res, q[-1][1]-q[0][1]+1)
            while len(q):
                cur, i = q.popleft()
                if cur.left: nx.append((cur.left, 2*i+1))
                if cur.right: nx.append((cur.right, 2*i+2))
            q = nx
        return res
__________________________________________________________________________________________________
