__________________________________________________________________________________________________
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def dfs(self,x):
        s=x.val;n=1;ans=0.0
        if x.left!=None:
            rtn=self.dfs(x.left)
            s+=rtn[0];n+=rtn[1];ans=max(ans,rtn[2])
        if x.right!=None:
            rtn=self.dfs(x.right)
            s+=rtn[0];n+=rtn[1];ans=max(ans,rtn[2])
        ans=max(ans,s/n)
        return [s,n,ans]
    def maximumAverageSubtree(self, root: TreeNode) -> float:
        rtn=self.dfs(root)
        return rtn[2]
__________________________________________________________________________________________________

__________________________________________________________________________________________________
