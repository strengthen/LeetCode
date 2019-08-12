__________________________________________________________________________________________________
sample 52 ms submission
"""
# Definition for a Node.
class Node:
    def __init__(self, val, left, right, next):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        stack=[]
        if not root:
            return root
        root.next=None
        if root.left:
            stack.append(root.left)
        # if root.right:
            stack.append(root.right)
        while stack:
            for _ in range(len(stack)-1):
                node=stack.pop(0)
                node.next=stack[0]
                if node.left:
                    stack.append(node.left)
                # if node.right:
                    stack.append(node.right)
            node=stack.pop(0)
            node.next=None
            
            if node.left:
                stack.append(node.left)
            # if node.right:
                stack.append(node.right)
        return root
__________________________________________________________________________________________________
sample 15172 kb submission
"""
# Definition for a Node.
class Node:
    def __init__(self, val, left, right, next):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root == None:
            return root
        queue = [root]
        count = 1
        while queue:
            new_queue = []
            pre = None
            for cur in queue:
                if pre:
                    pre.next = cur
                pre = cur
                if cur.left:
                    new_queue.append(cur.left)
                if cur.right:
                    new_queue.append(cur.right)
            queue = new_queue
        return root
__________________________________________________________________________________________________
