__________________________________________________________________________________________________
sample 28 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        def node_values(nodes):
            values = []
            for node in nodes:
                if node is not None:
                    values.append(node.val)
            return values
        
        def node_childs(nodes):
            childs = []
            for node in nodes:
                if node is not None:
                    childs.append(node.left)
                    childs.append(node.right)
            return childs
                
        answer = []
        queue  = [root]
        while queue:
            values = node_values(queue)
            if values:
                answer.insert(0,values)
            queue = node_childs(queue)
        
        return answer
__________________________________________________________________________________________________
sample 13128 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        
        res, s, q = [], [], [root]
        
        while q:
            temp = []
            for i in range(len(q)):
                v = q.pop()
                if v.left != None:
                    q.insert(0,v.left)
                
                if v.right != None:
                    q.insert(0,v.right)
                    
                temp.append(v.val)
            
            s.append(temp)
            
        while s:
            res.append(s.pop())
            
        return res
__________________________________________________________________________________________________
