__________________________________________________________________________________________________
sample 556 ms submission
class Solution:
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        def connected(i, j):
            if (i == 0 or matrix[i-1][j] >= level) and (j == 0 or matrix[i][j-1] >= level) and (i+1 == m or matrix[i+1][j] >= level) and (j+1 == n or matrix[i][j+1] >= level):
                return False
            return True
        
        q = collections.deque()
        m = len(matrix)
        n = len(matrix[0])
        for i in range(m):
            for j in range(n):
                if matrix[i][j]==1:
                    q.append((i, j))
                    
        level = 1
        while q:
            new = collections.deque()
            while q:
                i, j = q.popleft()
                if not connected(i, j):
                    matrix[i][j] = level + 1
                    new.append((i, j))
            level += 1
            q = new
                
        return matrix
__________________________________________________________________________________________________
sample 14676 kb submission
class Solution:
    def updateMatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        m = len(matrix)
        n = len(matrix[0])
        for i in range(m):
            for j in range(n):
                if matrix[i][j]:
                    matrix[i][j] = min(matrix[i - 1][j] + 1 if i > 0 else float('inf'), matrix[i][j - 1] + 1 if j > 0 else float('inf'))
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if matrix[i][j]:
                    matrix[i][j] = min(matrix[i + 1][j] + 1 if i < m - 1 else float('inf'), matrix[i][j + 1] + 1 if j < n - 1 else float('inf'), matrix[i][j])
        return matrix
__________________________________________________________________________________________________
