__________________________________________________________________________________________________
sample 28 ms submission
import math
class Solution:
    def numSquarefulPerms(self, A: List[int]) -> int:
        squares = {}
        left = {}
        empty_set = set()
        
        ret = [0]

        for i in range(len(A)):
            for j in range(i + 1, len(A)):
                sqrt = int(math.sqrt(A[i] + A[j]))
                
                if sqrt * sqrt == (A[i] + A[j]):
                    s = squares.setdefault(A[i], set())
                    s.add(A[j])
                    s = squares.setdefault(A[j], set())
                    s.add(A[i])
                    
            if A[i] not in left:
                left[A[i]] = 0
            left[A[i]] += 1
                    
        def dfs(prev, i):
            if i == len(A):
                ret[0] += 1
                return
            
            for val in list(left.keys()):
                
                if val in squares.get(prev, set()):
                    if (left[val] == 1):
                        del left[val]
                    else:
                        left[val] -= 1
                    dfs(val, i + 1)
                    if val not in left:
                        left[val] = 0
                    left[val] += 1
        
        
        for val in list(left.keys()):
            if (left[val] == 1):
                del left[val]
            else:
                left[val] -= 1
            dfs(val, 1)
            if val not in left:
                left[val] = 0
            left[val] += 1
            
        return ret[0]
__________________________________________________________________________________________________
sample 13136 kb submission
class Solution:
    def numSquarefulPerms(self, A: List[int]) -> int:
        count = collections.Counter(A)
        comb = {i: {j for j in count if int((i+j)**0.5)**2 == (i+j)} for i in count}
        self.result = 0
        def dfs(x, deep):
            if deep == 0:
                self.result += 1
                return
            count[x] -= 1
            for i in comb[x]:
                if count[i]:
                    dfs(i, deep - 1)
            count[x] += 1
        for i in comb:
            dfs(i, len(A)-1)
        return self.result
__________________________________________________________________________________________________
