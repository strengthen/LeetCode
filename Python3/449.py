__________________________________________________________________________________________________
sample 24 ms submission
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        self.root = root
        return ''
                
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        return self.root
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
__________________________________________________________________________________________________
sample 19316 kb submission
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        res = []
        def rserialize(root, res):
            if not root:
                res.append("None")
                return
            res.append(str(root.val))
            rserialize(root.left, res)
            rserialize(root.right, res)
        
        rserialize(root, res)
        return ",".join(res)
            
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        minval, maxval = float("-inf"), float("inf")
        def rdeserialize(data, minval, maxval):
            if data[0] == "None":
                data.pop(0)
                return None
            val = int(data.pop(0))
            if minval < val < maxval:
                root = TreeNode(val)
                root.left = rdeserialize(data, minval, val)
                root.right = rdeserialize(data, val, maxval)
                return root
                
        data = data.split(",")
        return rdeserialize(data, minval, maxval)
            

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
__________________________________________________________________________________________________
