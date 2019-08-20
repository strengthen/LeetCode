__________________________________________________________________________________________________
sample 44 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def tree2str(self, t: TreeNode) -> str:
        def DFS(root, string):
            if root:
                string = str(root.val)
                if (not root.right) and (not root.left):
                    return string
                elif root.right:
                    string += '(' + DFS(root.left, string) + ')'
                    string += '(' + DFS(root.right, string) + ')'
                else:
                    string += '(' + DFS(root.left, string) + ')'
            else:
                return ''
            return string
        string = ""
        return DFS(t, string)
__________________________________________________________________________________________________
sample 14748 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def tree2str(self, t: TreeNode) -> str:
        
        if not t:
            return ''
        stack = [t]
        visited = set()
        s = ''
        
        while stack:
            t = stack[-1]
            if t in visited:
                stack.pop()
                s+=')'
            else:
                visited.add(t)
                s+='('+str(t.val)
                if not t.left and t.right:
                    s+= '()'
                if t.right:
                    stack.append(t.right)
                if t.left:
                    stack.append(t.left)
        return s[1:len(s)-1]
__________________________________________________________________________________________________
