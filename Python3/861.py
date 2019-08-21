__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def matrixScore(self, A: List[List[int]]) -> int:
        n = len(A)
        for i in range(n):
            if A[i][0] == 0:
                A[i] = [1 - x for x in A[i]]
        result = 0
        for i in map(sum, zip(*A)):
            result = result * 2 + max(i, n - i)
        return result        
__________________________________________________________________________________________________
sample 12980 kb submission

class Solution:
    def matrixScore(self, A: List[List[int]]) -> int:
        R, C = len(A), len(A[0])

        # ensure 1st item in each row is 1
        for i in range(R):
            if A[i][0] == 0:
                for j in range(C):
                    A[i][j] = 1 - A[i][j]
        
        for i in range(C):
            tmp = 0

            for j in range(R):
                if A[j][i] == 0:
                    tmp += 1
            
            if tmp * 2 > R:
                for k in range(R):
                    A[k][i] = 1 - A[k][i]
        
        return self._matrixToScore(A)
    
    def _matrixToScore(self, A):
        R, C = len(A), len(A[0])
        score = 0
        for i in range(R):
            tmp = 0
            for j in range(C):
                tmp = (tmp << 1) | A[i][j]
            score += tmp
        return score
__________________________________________________________________________________________________
