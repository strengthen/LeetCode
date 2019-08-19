__________________________________________________________________________________________________
sample 48 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import defaultdict
class Solution:
    def findFrequentTreeSum(self, root: TreeNode) -> List[int]:
        if root == None:
            return
        
        SUM = defaultdict(lambda:0)
        
        def calculate(node):
            sum = node.val
            if node.left!=None:
                sum += calculate(node.left)
            if node.right != None:
                sum += calculate(node.right)
            SUM[sum] += 1
            return sum
        
        calculate(root)
        
        max_val = max(SUM.values())
        res = []
        for a in SUM.keys():
            if SUM[a]==max_val:
                res.append(a)
        return res
__________________________________________________________________________________________________
sample 16860 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findFrequentTreeSum(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        ans = []
        def dfs(root):
            if not root:
                return 0
            
            left = dfs(root.left)
            right = dfs(root.right)
            mid = left + right + root.val
            ans.append(mid)
            return mid
        dfs(root)
        count = collections.Counter(ans)
        max_occur = max(count.values())
        #max_occur = max(count.items(), key = lambda x: x[1])
        
        return [k for k,v in count.items() if v == max_occur]
__________________________________________________________________________________________________
