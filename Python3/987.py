__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def verticalTraversal(self, root: TreeNode) -> List[List[int]]:
        d={}
        q = collections.deque()
        q.append((root,0,0))
        while q:
            node, pos,depth = q.popleft()
            if not pos in d: d[pos]=[]
            d[pos].append((node.val,depth))
            l,r = node.left, node.right
            if l: q.append((l, pos-1,depth+1))
            if r: q.append((r, pos+1,depth+1))
        res=[x[1] for x in sorted(list(d.items()), key = lambda x : x[0])]
        return [[j[0] for j in sorted(i, key = lambda x: (x[1],x[0]))]for i in res]
__________________________________________________________________________________________________
sample 13228 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def verticalTraversal(self, root: TreeNode) -> List[List[int]]:
        
        from collections import defaultdict
        d = defaultdict(list)
        
        q = [(root, 0)] if root else []
        while q:
            for v, x in sorted([(t.val, x) for t, x in q]):
                d[x].append(v)
                
            q = [(c, y) for t, x in q for c, y in [(t.left, x-1), (t.right, x+1)] if c]
            
        return [d[k] for k in sorted(d.keys())]      
__________________________________________________________________________________________________
