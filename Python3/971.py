__________________________________________________________________________________________________
sample 32 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def flipMatchVoyage(self, root: TreeNode, voyage: List[int]) -> List[int]:
        voyage.reverse()
        ans = []
        def f(n):
            nonlocal ans, voyage
            sw = 0
            if n is None:
                return True
            elif n.val != voyage[-1]:
                return False
            else:
                voyage.pop()
                if f(n.left) is False and (not ans or ans[-1] > 0):
                    sw += 1
                    ans.append(n.val)
                    n.left, n.right = n.right, n.left
                    
                if sw == 1 and f(n.left) is False:
                    ans.append(-1)
                    return False
                if f(n.right) is False:
                    ans.append(-1)
                    return False
                return True
        ok = f(root)
        return [-1] if not ok or (ans and ans[-1] < 0) or voyage else ans
__________________________________________________________________________________________________
sample 13220 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def flipMatchVoyage(self, root: TreeNode, voyage: List[int]) -> List[int]:
        self.flipped = []
        self.i = 0

        def dfs(node):
            if node:
                if node.val != voyage[self.i]:
                    self.flipped = [-1]
                    return
                self.i += 1

                if (self.i < len(voyage) and
                        node.left and node.left.val != voyage[self.i]):
                    self.flipped.append(node.val)
                    dfs(node.right)
                    dfs(node.left)
                else:
                    dfs(node.left)
                    dfs(node.right)

        dfs(root)
        if self.flipped and self.flipped[0] == -1:
            self.flipped = [-1]
        return self.flipped
__________________________________________________________________________________________________
