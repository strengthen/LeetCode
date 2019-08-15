__________________________________________________________________________________________________
sample 72 ms submission
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
        result = []
        queue = [root]
        while queue:
            cur = queue.pop(0)
            result.append(str(cur.val) if cur else 'null')
            if cur:
                queue.append(cur.left)
                queue.append(cur.right)
        while result and result[-1] == 'null':
            result.pop()
        return '[' + ','.join(result) + ']'

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        def walk(n, i):
            if i >= n or data[i] == 'null' or data[i] == '':
                return None
            node = TreeNode(data[i] if data[i] != '' else '')
            node.left = walk(n, 2*i + 1)
            node.right = walk(n, 2*i + 2)
            return node
        data = data[1:-1].split()
        return walk(len(data), 0)

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
__________________________________________________________________________________________________
sample 17724 kb submission
class Codec:

    def serialize(self, root):
        if not root:
            return ''
        
        q = [root]
        index = 0
        
        while index < len(q):
            if q[index]:
                q.append(q[index].left)
                q.append(q[index].right)
            
            index += 1
        
        while not q[-1]:
            q.pop()
        
        return ','.join([str(item.val) if item else '#' for item in q])
        
    def deserialize(self, data):
        if not data:
            return None
        
        vals = data.split(',') # string list
        n = len(data)
        
        index = 0
        root = TreeNode(int(vals[0]))
        q = [root]
        isLeftChild = True
        
        for val in vals[1:]:
            if val != '#':
                node = TreeNode(int(val))
                
                if isLeftChild:
                    q[index].left = node
                else:
                    q[index].right = node
                q.append(node)
            
            if not isLeftChild:
                index += 1
            
            isLeftChild = not isLeftChild
        
        return root            
__________________________________________________________________________________________________
