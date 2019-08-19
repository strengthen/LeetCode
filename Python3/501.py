__________________________________________________________________________________________________
sample 44 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findMode(self, root: TreeNode) -> List[int]:
        
        if not root:
            return
        
        dic = {}
        
        def record(node):
            if not node:
                return
            
            if node.val not in dic:
                dic[node.val] = 1
            else:
                dic[node.val] += 1
                
            record(node.left)
            record(node.right)
            
        record(root)
        self.modes = []
        max_count = None
        
        for key, val in dic.items():
            if not max_count:
                self.modes.append(key)
                max_count = val
                
            elif val == max_count:
                self.modes.append(key)
            elif val > max_count:
                self.modes = [key]
                max_count = val
                
        return self.modes                
__________________________________________________________________________________________________
sample 17236 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def helper(self, root, cache):
        if root == None:
            return
        cache[root.val] += 1
        self.helper(root.left, cache)
        self.helper(root.right, cache)
        return
    
    def findMode(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if root == None:
            return []
        cache = collections.defaultdict(int)
        self.helper(root, cache)
        max_freq = max(cache.values())
        result = [k for k,v in cache.items() if v == max_freq]
        return result
__________________________________________________________________________________________________
