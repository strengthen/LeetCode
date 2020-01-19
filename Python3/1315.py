__________________________________________________________________________________________________
sample 76 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        
        if not root:
            return 0
        q = collections.deque([root])
        sum_ = 0
        while q:
            cur = q.popleft()
            l, r = cur.left, cur.right
            if l:
                q.append(l)
                if l.left and cur.val % 2 == 0:
                    sum_ += l.left.val
                if l.right and cur.val % 2 == 0:
                    sum_ += l.right.val
            if r:
                q.append(r)
                if r.left and cur.val % 2 == 0:
                    sum_ += r.left.val
                if r.right and cur.val % 2 == 0:
                    sum_ += r.right.val
        return sum_
__________________________________________________________________________________________________
sample 80 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        return self.helper(root, 1, 1)
    
    def helper(self, root:TreeNode, parent: int, gp: int) -> int:
        if root == None:
            return 0
        return self.helper(root.left, root.val, parent) + self.helper(root.right, root.val, parent) + (root.val if gp%2==0 else 0)
__________________________________________________________________________________________________
