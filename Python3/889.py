__________________________________________________________________________________________________
sample 48 ms submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def constructFromPrePost(self, pre: List[int], post: List[int]) -> TreeNode:
        p = 0
        root = TreeNode(pre[0])
        stack = [root]
        for i in range(1, len(pre)):
            node = None
            while stack and stack[-1].val == post[p]:
                node = stack.pop()
                p += 1
            newNode = TreeNode(pre[i])
            if node:
                stack[-1].right = newNode
            else:
                stack[-1].left = newNode
            stack.append(newNode)
        return root
__________________________________________________________________________________________________
sample 13028 kb submission
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def constructFromPrePost(self, pre: List[int], post: List[int]) -> TreeNode:
        stack = [TreeNode(pre[0])]
        j = 0
        for v in pre[1:]:
            node = TreeNode(v)
            while stack[-1].val == post[j]:
                stack.pop()
                j += 1
            if not stack[-1].left:
                stack[-1].left = node
            else:
                stack[-1].right = node
            stack.append(node)
        return stack[0]
__________________________________________________________________________________________________
