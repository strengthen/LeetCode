__________________________________________________________________________________________________
sample 20 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, node: TreeNode) -> List[int]:
        run = True 
        stack = []
        out = []
        currentNode = node
        while run:
            if currentNode:
                stack.append(currentNode)
                currentNode = currentNode.left

            else:
                if stack:
                    currentNode = stack.pop()
                    out.append(currentNode.val)
                    currentNode = currentNode.right

                else:
                    run = False
        return out
__________________________________________________________________________________________________
sample 12956 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        traversal = []
        self.getInOrder(root, traversal)
        return traversal
        
    def getInOrder(self, root, traversal):
        if not root:
            return
        self.getInOrder(root.left, traversal)
        traversal.append(root.val)
        self.getInOrder(root.right, traversal)
__________________________________________________________________________________________________
