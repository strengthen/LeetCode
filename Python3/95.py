__________________________________________________________________________________________________
sample 40 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        if n == 0: return []
        memo = {}
        return self.dfs(1, n, memo)

    def dfs(self, left, right, memo):
        if left > right: return [None]
        res = []
        if (left, right) in memo: return memo[(left, right)]
        for i in range(left, right+1):
            left_input = self.dfs(left, i-1, memo)    #divide
            right_input = self.dfs(i+1, right, memo)
            for left_num in left_input:         #conquer
                for right_num in right_input:
                    node = TreeNode(i)
                    node.left = left_num
                    node.right = right_num
                    res.append(node)
        memo[(left, right)] = res
        return res
        
__________________________________________________________________________________________________
sample 13884 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        if not n:
            return []
        if n==1:
            return [TreeNode(1)]
        return self.dfs(1,n,{})
        
    def dfs(self,start,end,memo):
        if (start,end) in memo:
            return memo[(start,end)]
        if start>end:
            return [None]
        if start==end:
            return [TreeNode(start)]
        trees=[]
        for i in range(start,end+1):
            for l in self.dfs(start,i-1,memo):
                for r in self.dfs(i+1,end,memo):
                    root=TreeNode(i)
                    root.left=l
                    root.right=r
                    trees.append(root)
        memo[(start,end)]=trees
        return trees
__________________________________________________________________________________________________
