__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def minDeletionSize(self, A: List[str]) -> int:
        n = len(A)
        flag = [True for _ in range(n)]
        
        x, k = 0, n
        for j in range(len(A[0])):
            i, idx = 0, []
            while i < n - 1:
                if flag[i]:
                    if A[i][j] > A[i + 1][j]:
                        x += 1
                        break
                        
                    if A[i][j] < A[i + 1][j]:
                        idx += [i]
                
                i += 1
            
            if i == n - 1:
                if k == len(idx):
                    return x
                
                k -= len(idx)
                for i in idx:
                    flag[i] = False
        
        return x
__________________________________________________________________________________________________
sample 44 ms submission
class Solution:
    def minDeletionSize(self, A: List[str]) -> int:
        
        def sortedColumn(col, check):
            nonlocal A
            if len(check) == 0 or col == len(A[0]):
                return 0
            newTies = []
            for tied in check:
                highest = ''
                currentTie = ''
                for r in tied:
                    if A[r][col] < highest:
                        return 1 + sortedColumn(col+1, check)
                    if A[r][col] == currentTie:
                        newTies[-1].append(r)
                    elif A[r][col] == highest:
                        currentTie = highest
                        newTies.append([r-1, r])
                    else:
                        highest = A[r][col]
                        
            return sortedColumn(col+1, newTies)
        
        return sortedColumn(0, [range(len(A))])
__________________________________________________________________________________________________
