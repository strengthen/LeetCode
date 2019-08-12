__________________________________________________________________________________________________
sample 24 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        
        levels = []
        lvl = 0
        from collections import deque
        q = deque([root,])
        while q:
            levels.append([])
            
            lvlLen = len(q)
            
            for _ in range(lvlLen):
                node = q.popleft()
                levels[lvl].append(node.val)
                
                
                if node.left:
                    q.append(node.left)
                    
                if node.right:
                    q.append(node.right)
                    
            lvl += 1
            
        return levels
__________________________________________________________________________________________________
sample 13144 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        return self.bfs(root)
    
        # bfs, time: O(n), space: O(n)
    def bfs(self,root):
        res = []
        cur, nex = [], [] # cur stores current level nodes, nex stores next level nodes
        cur.append(root)
        i = 0
        while cur != []:
            res.append([])
            for node in cur:
                res[i].append(node.val)
                if node.left:
                    nex.append(node.left)
                if node.right:
                    nex.append(node.right)
            cur, nex = nex, []
            i += 1
        return res
__________________________________________________________________________________________________
