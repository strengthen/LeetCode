__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def oddCells(self, n: int, m: int, indices: List[List[int]]) -> int:
        row, col = [False] * n, [False] * m
        for r, c in indices:
            row[r] ^= True
            col[c] ^= True
        # return m * sum(row) + n * sum(col) - 2 * sum(row) * sum(col)
        return (m - sum(col)) * sum(row) + (n - sum(row))* sum(col)        
__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def oddCells(self, n: int, m: int, indices: List[List[int]]) -> int:
        rows = [0]*n
        cols = [0]*m
        for rc in indices:
            rows[rc[0]] += 1
            cols[rc[1]] += 1

        oddCount = 0
        for i in range(n):
            for j in range(m):
                oddCount += (rows[i]+cols[j])%2
        return oddCount
__________________________________________________________________________________________________
