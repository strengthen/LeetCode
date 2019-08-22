__________________________________________________________________________________________________
sample 52 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def recoverFromPreorder(self, S: str) -> TreeNode:
        vals = [(len(s[0]), s[1]) for s in re.findall('(-*)(\d+)', S)][::-1]
        
        def fn(level):
            if not vals or level != vals[-1][0]:
                return None
            node = TreeNode(vals.pop()[1])
            node.left = fn(level+1)
            node.right = fn(level+1)
            return node
        
        return fn(0)
__________________________________________________________________________________________________
sample 13456 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def recoverFromPreorder(self, S: str) -> TreeNode:
        i, lookup = 0, {}
        while i < len(S):
            j = i
            while j < len(S) and S[j] == '-':
                j += 1
            dep = j-i
            k = j
            while k < len(S) and S[k].isdigit():
                k += 1
            node = TreeNode(int(S[j:k]))
            lookup[dep] = node
            if dep:
                p = lookup[dep-1]
                if not p.left:
                    p.left = node
                else:
                    p.right = node
            i = k
        return lookup[0]
__________________________________________________________________________________________________
