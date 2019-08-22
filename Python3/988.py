__________________________________________________________________________________________________
sample 44 ms submission
class Solution:
    def smallestFromLeaf(self, root: TreeNode) -> str:
        def convert(num):
            return chr(ord('a') + num)
            
        def dfs(node, pval):
            cur_val = convert(node.val)
            
            if not node.left and not node.right:
                return cur_val
            
            l = r = None
            if node.left:
                l = dfs(node.left, convert(node.val)) + cur_val

            if node.right:
                r = dfs(node.right, convert(node.val)) + cur_val

            if node.left and node.right:
                if l + pval > r + pval:
                    return r
                else:
                    return l
            
            return l or r
        
        ret = dfs(root, convert(root.val))
        return ret
    
    
    def smallestFromLeaf(self, root: TreeNode) -> str:
        
        def convert(num):
            return chr(ord('a') + num)
    
        def dfs(node, pval):
            if not node:
                return ''
            
            val = convert(node.val)
            if not node.left and not node.right:
                return val
            
            lval = rval = ''
            if node.left:
                lval = dfs(node.left, val) + val
            if node.right:
                rval = dfs(node.right, val) + val
            
            if not node.left or not node.right:
                return lval or rval
            
            if lval + pval < rval + pval:
                return lval
            return rval
        
        return dfs(root, convert(root.val))
__________________________________________________________________________________________________
sample 14560 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def smallestFromLeaf(self, root: TreeNode) -> str:
        def dfs(node, path):
            if not node:
                return
            path.append(chr(ord('a') + node.val))
            if not node.left and not node.right:
                res[0] = min(res[0], ''.join(path)[::-1])
            else:
                dfs(node.left, path)
                dfs(node.right, path)
            del path[-1]
        
        res = [str(chr(ord('z') + 1))]
        dfs(root, [])
        return res[0]
__________________________________________________________________________________________________
