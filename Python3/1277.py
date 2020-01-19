__________________________________________________________________________________________________
sample 576 ms submission
class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        prev_row = None
        s = 0
        for row in matrix:
            prev_x = None
            for i, x in enumerate(row):
                if x == 0:
                    prev_x = x
                    continue
                if prev_x and prev_row:
                    x = row[i] = min(prev_row[i - 1], prev_row[i], prev_x) + 1
                s += x
                prev_x = x
            prev_row = row
        return s
__________________________________________________________________________________________________
sample 580 ms submission
class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        
        dp = [list(row) for row in matrix]
        R = len(dp)
        C = len(dp[0])
        
        for r in range(1, R):
            for c in range(1, C):
                if dp[r][c] and dp[r-1][c] and dp[r][c-1] and dp[r-1][c-1]:
                    dp[r][c] += min(dp[r-1][c], dp[r][c-1], dp[r-1][c-1])
                            
        ans = sum([sum(row) for row in dp])
        return ans
__________________________________________________________________________________________________
