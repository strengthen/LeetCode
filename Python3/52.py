__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def totalNQueens(self, n: int) -> int:
        self.count = 0
        def DFS(n, row, cols, pie, na):
            bits = (~(cols | pie | na)) & ((1 << n) - 1)
            while bits:
                p = bits & -bits
                if row == n - 1:
                    self.count += 1
                else:
                    DFS(n, row + 1,cols | p,(pie | p) << 1,(na | p) >> 1)
                bits = bits & (bits - 1)
        DFS(n,0,0,0,0)
        return self.count
__________________________________________________________________________________________________
sample 12756 kb submission
class Solution:
    def totalNQueens(self, n: int) -> int:
        return self.backtrack([], n)
        
    def backtrack(self, tmpSet, n):
        if len(tmpSet) == n:
            return 1
        x = 0
        for i in range(n):
            if self.isValid(tmpSet, i):
                tmpSet.append(i)
                x += self.backtrack(tmpSet, n)
                tmpSet.pop()
        return x
                
    def isValid(self, tmpSet, i):
        n = len(tmpSet)
        for j in range(len(tmpSet)):
            if i == tmpSet[j]:
                return False
            if abs(n - j) == abs(i - tmpSet[j]):
                return False
        return True
__________________________________________________________________________________________________
