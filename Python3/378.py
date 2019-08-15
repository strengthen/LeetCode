__________________________________________________________________________________________________
sample 180 ms submission
class Solution:
    """
    @param matrix: a matrix of integers
    @param k: An integer
    @return: the kth smallest number in the matrix
    """
    def kthSmallest(self, matrix, k):
        l, r = matrix[0][0], matrix[-1][-1]
        while l <= r :
            m = (l + r) // 2
            count = 0
            for row in matrix:
                count += bisect.bisect_right(row, m)
            if k > count:
                l = m + 1
            else:
                r = m - 1
        return l
__________________________________________________________________________________________________
sample 17172 kb submission
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        
        if not matrix or not matrix[0]:
            return 0
        
        l = matrix[0][0]
        r = matrix[-1][-1]
        
        m = len(matrix)
        n = len(matrix[0])
        
        while l < r:
            
            mid = l + (r - l) // 2
            cnt = 0
            j = n - 1
            
            for i in range(m):
                while j >= 0 and matrix[i][j] > mid:
                    j -= 1

                cnt += (j + 1)
                
            if cnt < k:
                l = mid + 1
            else:
                r = mid
        
        return l
__________________________________________________________________________________________________
