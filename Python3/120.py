__________________________________________________________________________________________________
sample 56 ms submission
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        if len(triangle) == 1:
            return triangle[0][0]
        
        triangle[1][0] += triangle[0][0]
        triangle[1][1] += triangle[0][0]
        
        if len(triangle) == 2:
            return min(triangle[1][0], triangle[1][1])
        
        for i in range(2, len(triangle)):
            for j in range(len(triangle[i])):
                if j == 0:
                    triangle[i][j] += triangle[i-1][j]
                elif j == len(triangle[i])-1:
                    triangle[i][j] += triangle[i-1][j-1]
                else:
                    triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j])
        return min(triangle[-1])            
__________________________________________________________________________________________________
sample 13376 kb submission
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        if not triangle:
            return 0
        m = len(triangle)
        dp = triangle[m - 1][:]
        for i in range(m - 2, -1, -1):
            for j in range(len(triangle[i])):
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1])
        return dp[0]
__________________________________________________________________________________________________
