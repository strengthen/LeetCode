__________________________________________________________________________________________________
sample 372 ms submission
class Solution:
    def longestIncreasingPath(self, matrix):
        if not matrix: return 0
        def dfs(i, j):
            if not dp[i][j]:
                val = matrix[i][j]
                dp[i][j] = 1 + max(
                    dfs(i - 1, j) if i and val < matrix[i - 1][j] else 0,
                    dfs(i + 1, j) if i < M - 1 and val < matrix[i + 1][j] else 0,
                    dfs(i, j - 1) if j and val < matrix[i][j - 1] else 0,
                    dfs(i, j + 1) if j < N - 1 and val < matrix[i][j + 1] else 0)
            return dp[i][j]

        M, N = len(matrix), len(matrix[0])
        dp = [[0] * N for i in range(M)]
        return max(dfs(x, y) for x in range(M) for y in range(N))
__________________________________________________________________________________________________
sample 13312 kb submission
class Solution(object):
    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        if not matrix: return 0
        self.directions = [(1,0),(-1,0),(0,1),(0,-1)]
        m = len(matrix)
        n = len(matrix[0])
        cache = [[-1 for _ in range(n)] for _ in range(m)]
        res = 0
        for i in range(m):
            for j in range(n):
                cur_len = self.dfs(i, j, matrix, cache, m, n)
                res = max(res, cur_len)
        return res
        
    def dfs(self, i, j, matrix, cache, m, n):
        if cache[i][j] != -1:
            return cache[i][j]
        res = 1
        for direction in self.directions:
            x, y = i + direction[0], j + direction[1]
            if x < 0 or x >= m or y < 0 or y >= n or matrix[x][y] <= matrix[i][j]:
                continue
            length = 1 + self.dfs(x, y, matrix, cache, m, n)
            res = max(length, res)
        cache[i][j] = res
        return res
__________________________________________________________________________________________________
