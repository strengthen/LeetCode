__________________________________________________________________________________________________
60ms
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import re

class Solution:
    def recoverFromPreorder(self, S: str) -> TreeNode:
        nodes = []
        idx = 0
        nodes = [(int(v), len(d)) for d, v in re.findall(r'(-*)(\d+)', S)]
                
        root = TreeNode(nodes[0][0])
        stack = []
        stack.append((root, nodes[0][1]))
        for node in nodes[1:]:
            tn = TreeNode(node[0])
            stack_top, stack_depth = stack[-1]
            if stack_depth + 1 == node[1]:
                if stack_top.left is None:
                    stack_top.left = tn
                else:
                    stack_top.right = tn
            else:
                while len(stack) > 0 and stack[-1][1] >= node[1]:
                    stack.pop()
                stack_top = stack[-1][0]
                stack_top.right = tn
            stack.append((tn, node[1]))
        return root               
__________________________________________________________________________________________________
68ms
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque

class Solution:
        
    def recoverFromPreorder(self, S: str) -> TreeNode:
        wayback = deque()
        if '-' not in S:
            return TreeNode(S)
        
        root = TreeNode(S[0:S.index('-')])
        head = root
        head_depth = 0
        for node, depth in self.get_depths(S[S.index('-'):]):
            if depth == head_depth + 1:
                wayback.append(head)
                head.left = node
                head = node
            else:
                for _ in range(head_depth - depth):
                    wayback.pop()
                head = wayback[-1]
                head.right = node
                head = node
            head_depth = depth
        return root
        
    def get_depths(self, S):
        depth = 0
        val = ''
        for char in S:
            if char == '-':
                if val != '':
                    yield TreeNode(val), depth
                    depth = 0
                    val = ''
                depth += 1
            else:
                val += char
        yield TreeNode(val), depth
__________________________________________________________________________________________________
72ms
class Solution:
    def recoverFromPreorder(self, S: str) -> TreeNode:
        def popAndLinkTopLeft(stack: List[int]):
            pop = stack.pop(-1)
            top = stack.pop(-1)
    
            if isinstance(top, tuple):
                top_x, top_y = top
                if isinstance(pop, tuple):
                    top_y.left = pop[0]
                    top_y.right = pop[1]
                else:
                    top_y.left = pop
                top = top_x, top_y
            elif isinstance(pop, tuple):
                top.left = pop[0]
                top.right = pop[1]
            else:
                top.left = pop
            stack.append(top)
        
        def doubleStack(stack, right):
            left = stack.pop(-1)
            stack.append((left, right))
        
        def addToStack(n: TreeNode, stack: List[int], height: int):
            if len(stack) < height+1:
                stack.append(n)
                return
            # stack collision
            # make it even
            while len(stack) > height+1:
                popAndLinkTopLeft(stack)
            # Siblings found
            doubleStack(stack, n)

        stack = []
        h = 0
        number = False
        temp_number = ''
        
        for char in S:
            if char == '-':
                if number:
                    addToStack(TreeNode(temp_number), stack, h)
                    h = 0
                    temp_number = ''
                h += 1
                number = False
            else:
                if not number:
                    number = True
                temp_number += char

        if temp_number:
            addToStack(TreeNode(temp_number), stack, h)
        while len(stack) > 1:
            popAndLinkTopLeft(stack)            
        return stack.pop()

__________________________________________________________________________________________________
76ms
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def parse_depth_values(self, string):
        depth_values = collections.deque()
        n = len(string)
        i = 0

        while i < n:
            d = i
            while string[i] == '-':
                i += 1

            v = i
            while i < n and string[i].isdigit():
                i += 1

            depth = v - d
            value = int(string[v:i])
            depth_values.append((depth, value))

        return depth_values

    def tree_from_depth_values(self, depth_values, depth):
        if depth_values and depth_values[0][0] == depth:
            _, val = depth_values.popleft()
            node = TreeNode(val)
            node.left = self.tree_from_depth_values(depth_values, depth + 1)
            node.right = self.tree_from_depth_values(depth_values, depth + 1)
            return node

        else:
            return None
    
    def recoverFromPreorder(self, s: str) -> TreeNode:
        depth_values = self.parse_depth_values(s)
        tree = self.tree_from_depth_values(depth_values, 0)
        return tree
__________________________________________________________________________________________________
80ms
class Solution:
    def recoverFromPreorder(self, S):
        stack, i = [], 0
        while i < len(S):
            level, val = 0, ""
            while i < len(S) and S[i] == '-':
                level, i = level + 1, i + 1
            while i < len(S) and S[i] != '-':
                val, i = val + S[i], i + 1
            while len(stack) > level:
                stack.pop()
            node = TreeNode(val)
            if stack and stack[-1].left is None:
                stack[-1].left = node
            elif stack:
                stack[-1].right = node
            stack.append(node)
        return stack[0]
__________________________________________________________________________________________________