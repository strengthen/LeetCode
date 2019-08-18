__________________________________________________________________________________________________
sample 132 ms submission
"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""
class Solution:
    def construct(self, grid: List[List[int]]) -> 'Node':
        
        if not grid:
            return None
        
        if self.isLeaf(grid):
            return Node(grid[0][0] == 1, True, None, None, None, None)
        
        N = len(grid)
        
        return Node(
            '*',
            False,
            self.construct([row[:N//2] for row in grid[:N//2]]),
            self.construct([row[N//2:] for row in grid[:N//2]]),
            self.construct([row[:N//2] for row in grid[N//2:]]),
            self.construct([row[N//2:] for row in grid[N//2:]])
        )
    
    def isLeaf(self, grid):
        
        n = len(grid)
        
        total = sum(list(map(sum, grid)))
        
        return total == 0 or total == n * n
__________________________________________________________________________________________________
sample 136 ms submission
"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""
class Solution:
    # import numpy as np
    def isSame(self,grid):
        if not grid:
            return True
        first = grid[0][0]
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]!=first:
                    return False
        return True
    def construct(self, grid: List[List[int]]) -> 'Node':
        # grid = np.array(grid)
        # print(grid)
        N = len(grid)
        root = Node(True,False)
        if self.isSame(grid) or N == 1:
            root.isLeaf = True
            root.val = grid[0][0]
            return root
        root.isLeaf = False
        root.val = '*'
        root.topLeft = self.construct([i[:N//2] for i in grid[:N//2]])
        root.topRight = self.construct([i[N//2:] for i in grid[:N//2]])
        root.bottomLeft = self.construct([i[:N//2] for i in grid[N//2:]])
        root.bottomRight = self.construct([i[N//2:] for i in grid[N//2:]])
        return root
__________________________________________________________________________________________________
