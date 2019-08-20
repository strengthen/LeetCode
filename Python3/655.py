__________________________________________________________________________________________________
sample 28 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def printTree(self, root: TreeNode) -> List[List[str]]:
        def getHeight(node):
            if node == None: return 0
            return 1 + max(getHeight(node.left), getHeight(node.right))
        
        h = getHeight(root)
        w = pow(2, h) - 1
        
        arr = [["" for _ in range(w)] for _ in range(h)]
        def printNode(node, depth, min_v, max_v, arr):
            if node == None: return
            mid = (min_v + max_v) // 2
            arr[depth][mid] = str(node.val)
            printNode(node.left, depth+1, min_v, mid-1, arr)
            printNode(node.right, depth+1, mid+1, max_v, arr)
        
        printNode(root, 0, 0, w, arr)
        return arr
__________________________________________________________________________________________________
sample 32 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque
class Solution:
    def printTree(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[str]]
        """
        def get_height(node):
            result = 0
            if node is not None:
                stk = deque([(node, 1)])
                while stk:
                    node, ht = stk.pop()
                    if ht > result:
                        result = ht
                    if node.left is not None:
                        stk.append((node.left, ht + 1))
                    if node.right is not None:
                        stk.append((node.right, ht + 1))
            return result
        
        # Iterative version with additional stack.
        def update_output(node, row, left, right, out):
            if node is None:
                return
            stk = deque([(node, 0, left, right)])
            while stk:
                node, depth, left, right = stk.pop()
                mid = left + ((right - left) // 2)
                out[depth][mid] = str(node.val)
                if node.left is not None:
                    stk.append((node.left, depth + 1, left, mid))
                if node.right is not None:
                    stk.append((node.right, depth + 1, mid + 1, right))
        
        # Number of rows
        height = get_height(root)
        # Number of columns can be guessed from examples.
        # Or, think about this:
        # (1) You'll need 2 ** (height - 1) blanks for leaf node.
        # (2) You'll also need 2 ** (height - 2) blanks to place
        #     parents of leaves.
        # (3) So far so on for all parents.
        # ==> Hence, you'll need
        #     2 ** (height - 1) + 2 ** (height - 2) + ...
        #     + 2 ** (0) = 2 ** height - 1.
        width = 2 ** height - 1
        output = [[''] * width for i in range(height)]
        update_output(root, 0, 0, width, output)
        return output
__________________________________________________________________________________________________
