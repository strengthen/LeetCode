__________________________________________________________________________________________________
sample 24 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def distanceK(self, root, target, K):
        ans = []

        # Return distance from node to target if exists, else -1
        # Vertex distance: the # of vertices on the path from node to target
        def dfs(node):
            if not node:
                return -1
            elif node is target:
                subtree_add(node, 0)
                return 1
            else:
                L, R = dfs(node.left), dfs(node.right)
                if L != -1:
                    if L == K: 
                        ans.append(node.val)
                        # return -1
                    subtree_add(node.right, L + 1)
                    return L + 1
                elif R != -1:
                    if R == K: 
                        ans.append(node.val)
                        # return -1
                    subtree_add(node.left, R + 1)
                    return R + 1
                else:
                    return -1

        # Add all nodes 'K - dist' from the node to answer.
        def subtree_add(node, dist):
            if not node:
                return
            elif dist == K:
                ans.append(node.val)
            else:
                subtree_add(node.left, dist + 1)
                subtree_add(node.right, dist + 1)

        dfs(root)
        return ans
__________________________________________________________________________________________________
sample 13016 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def distanceK(self, root, target, K):
        """
        :type root: TreeNode
        :type target: TreeNode
        :type K: int
        :rtype: List[int]
        """
        stack = []
        def dfs(root):
            if root is target:
                stack.append(root)
                return True
            if root is None:
                return False
            stack.append(root)
            if dfs(root.right) or dfs(root.left):
                return True
            stack.pop()
            return False
        dfs(root)
        stack.reverse()
        ans = []
        def getNode(root,distance):
            if root is None:
                return
            if distance == 0:
                ans.append(root.val)
                return
            if not stack or root.left is not stack[-1]:
                getNode(root.left, distance-1)
            if not stack or root.right is not stack[-1]:
                getNode(root.right, distance-1)
            return
        while stack:
            node = stack.pop()
            if K - len(stack) < 0:
                continue
            getNode(node,K - len(stack))
        return ans        
__________________________________________________________________________________________________
