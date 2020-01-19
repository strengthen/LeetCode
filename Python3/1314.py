__________________________________________________________________________________________________
sample 84 ms submission
class Solution:
    def matrixBlockSum(self, mat: List[List[int]], K: int) -> List[List[int]]:
        m = len(mat[0])
        n = len(mat)
        
        sum_map = [[0 for i in range(m)] for j in range(n)]
        
        for y in range(n):
            x_sum = 0
            for x in range(m):
                prev_y = 0
                if y > 0:
                    prev_y = sum_map[y - 1][x]
                sum_map[y][x] = mat[y][x] + x_sum + prev_y
                x_sum += mat[y][x]
                
        result = [[0 for i in range(m)] for j in range(n)]
        
        for y in range(n):
            for x in range(m):
                start_x = x - K
                start_y = y - K 
                bound_x = x + K
                bound_y = y + K

                if start_x < 0:
                    start_x = 0        
                if start_y < 0:
                    start_y = 0
                    
                if bound_x >= m:
                    bound_x = m - 1         
                if bound_y >= n:
                    bound_y = n - 1
                    
                if start_x == 0 and start_y == 0:
                    result[y][x] = sum_map[bound_y][bound_x]
                    continue
                if start_y == 0:
                    result[y][x] = sum_map[bound_y][bound_x] - sum_map[bound_y][start_x - 1]
                    continue
                if start_x == 0:
                    result[y][x] = sum_map[bound_y][bound_x] - sum_map[start_y - 1][bound_x]
                    continue
                result[y][x] = sum_map[bound_y][bound_x] - sum_map[bound_y][start_x - 1] - (sum_map[start_y - 1][bound_x] - sum_map[start_y - 1][start_x - 1])
            
        return result
__________________________________________________________________________________________________
sample 88 ms submission
class Solution:
    def matrixBlockSum(self, mat: List[List[int]], K: int) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        for i in range(1, m):
            for j in range(n):
                mat[i][j] += mat[i-1][j]
        for j in range(1, n):
            for i in range(m):
                mat[i][j] += mat[i][j-1]
        res = [[0]*n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                idx1, idx2, idx3, idx4 = i-K, j-K, i+K, j+K
                if idx1 < 0:
                    idx1 = 0
                if idx2 < 0:
                    idx2 = 0
                if idx3 >= m:
                    idx3 = m-1
                if idx4 >= n:
                    idx4 = n-1
                sum1 = mat[idx3][idx4]
                sum2 = mat[idx1-1][idx4] if idx1 > 0 else 0
                sum3 = mat[idx3][idx2-1] if idx2 > 0 else 0
                sum4 = mat[idx1-1][idx2-1] if (idx1 > 0 and idx2 > 0) else 0
                res[i][j] = sum1-sum2-sum3+sum4
        return res
__________________________________________________________________________________________________
