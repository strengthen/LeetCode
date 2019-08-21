__________________________________________________________________________________________________
sample 136 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def allPossibleFBT(self, N: int) -> List[TreeNode]:
        def rec(N):
            res = []
            for i in range(1,N,2):
                for left in self.memo[i]:
                    for right in self.memo[N-i-1]:
                        root = TreeNode(0)
                        root.left = left
                        root.right = right
                        res.append(root)
            self.memo[N] = res
        self.memo = {1:[TreeNode(0)]}
        if N % 2 == 0:
            return []
        for i in range(3, N+1, 2):
            rec(i)
        return self.memo[N]
__________________________________________________________________________________________________
sample 16204 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def allPossibleFBT(self, N: int) -> List[TreeNode]:
        if N % 2 == 0: 
            return [] # the number of node must be odd
        cache = {}
        for i in range(1,N+1,2): # only consider odd number
            if i == 1:  # initialize
                cache[1] = [TreeNode(0)]
                continue
            cache[i] = []
            for j in range(1,i,2): # j represent the number of node in left child
                for lkid in cache[j]:
                    for rkid in cache[i-1-j]:
                        node = TreeNode(0)
                        node.left = lkid
                        node.right = rkid
                        cache[i].append(node)
        return cache[N]
__________________________________________________________________________________________________
