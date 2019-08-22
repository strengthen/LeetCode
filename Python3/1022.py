__________________________________________________________________________________________________
sample 32 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumRootToLeaf(self, root: TreeNode) -> int:
        if root is None:
            return 0
        
        def help(root, cur):
            if root is None:
                return 0
            
            if root.left is None and root.right is None:
                return cur
            
            ans = 0
            if root.left:
                ans += help(root.left, 2 * cur + root.left.val)
            
            if root.right:
                ans += help(root.right, 2 * cur + root.right.val)
            return ans
        
        return help(root, root.val)
__________________________________________________________________________________________________
sample 13244 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumRootToLeaf(self, root: TreeNode) -> int:
        res = []
        def recur(node, path):
            path.append(node.val)
            if not node.left and not node.right:
                res.append(path[:])
                path.pop()
                return
            if node.left:
                recur(node.left, path)
            if node.right:
                recur(node.right, path)
            path.pop()
        recur(root, [])
        ans = 0
        for num in res:
            ans += self.getDec(num)
        return ans
            
    
    def getDec(self, res):
        num = 0
        index = 0
        for i in range(len(res) - 1, -1, -1):
            num += (2**index) * res[i]
            index += 1
        return num
__________________________________________________________________________________________________
