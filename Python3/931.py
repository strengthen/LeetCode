__________________________________________________________________________________________________
sample 116 ms submission
class Solution:
    def minFallingPathSum(self, A):
        n = len(A)
        tmp = [ A[0][::]  for i in range(2)]

        for i in range(1, n):
            for j in range(n):
                t1 = tmp[(i-1)%2]
                m = t1[j]
                if j > 0 and  m > t1[j-1]:
                    m = t1[j-1]
                if j < n-1 and m > t1[j+1]:
                    m = t1[j+1]
                tmp[i%2][j] = A[i][j] +  m

        return min(tmp[(n-1)%2])
__________________________________________________________________________________________________
sample 13532 kb submission
class Solution:
    def minFallingPathSum(self, A: List[List[int]]) -> int:
        change = [0]* len(A)
        for row in A:
            new_change = [1e10]*len(row)
            for i in range(len(A[0])):
                for delta in [-1, 0, 1]:
                    if i+delta >= 0 and i+delta < len(row):
                            new_change[i] = min(new_change[i], change[i+delta]+row[i])
            change = new_change
        return min(change)
__________________________________________________________________________________________________
