__________________________________________________________________________________________________
sample 44 ms submission

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def find_dupes(self, root, signatures, result):
        if root is None:
            return "#"
        else:
            left = self.find_dupes(root.left, signatures, result)
            right = self.find_dupes(root.right, signatures, result)
            sign = "".join([str(root.val), left, right])
            signatures[sign] += 1
            if signatures[sign] == 2:
                result.append(root)
            return sign
    
    def findDuplicateSubtrees(self, root):
        """
        :type root: TreeNode
        :rtype: List[TreeNode]
        """
        signatures, result = collections.defaultdict(int), []
        self.find_dupes(root, signatures, result)
        return result
__________________________________________________________________________________________________
sample 17032 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findDuplicateSubtrees(self, root: TreeNode) -> List[TreeNode]:
        trees = collections.defaultdict()
        trees.default_factory = trees.__len__
        count = collections.Counter()
        ans = []
        def lookup(node):
            if node:
                uid = trees[node.val, lookup(node.left), lookup(node.right)]
                count[uid] += 1
                if count[uid] == 2:
                    ans.append(node)
                return uid
        
        lookup(root)
        return ans
__________________________________________________________________________________________________
