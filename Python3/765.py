__________________________________________________________________________________________________
sample 28 ms submission
class Solution(object):
    def minSwapsCouples(self, row):
        ans = 0
        for i in range(0, len(row), 2):
            x = row[i]
            if row[i+1] == x^1: continue
            ans += 1
            for j in range(i+1, len(row)):
                if row[j] == x^1:
                    row[i+1], row[j] = row[j], row[i+1]
                    break
        return ans
__________________________________________________________________________________________________
sample 13208 kb submission
class UnionFind:
    def __init__(self, N):
        self.parents = [i for i in range(N)]
        self.count = 0
        
    def find(self, x):
        if self.parents[x] == x:
            return x
        return self.find(self.parents[x])
    
    def union(self, x, y):
        px = self.find(x)
        py = self.find(y)
        if px != py:
            self.count += 1
        self.parents[py] = px
        
class Solution:
    def minSwapsCouples(self, row: List[int]) -> int:
        N = len(row) // 2
        UF = UnionFind(N)
        for i in range(N):
            x_couple = row[i * 2] // 2
            y_couple = row[i * 2 + 1] // 2
            if x_couple != y_couple:
                UF.union(x_couple, y_couple)
                
        return UF.count        
__________________________________________________________________________________________________
