__________________________________________________________________________________________________
class Solution:
    def minimumCost(self, N: int, conections: List[List[int]]) -> int:
        
        if len(conections) < N-1:
            return -1
        
        parent = list(range(N+1))
        
        def find(x):
            while parent[x] != x:
                x = parent[x]
            return x
        
        res = 0
        for c1, c2, cost in sorted(conections, key = lambda x: x[2]):
            p1, p2 = find(c1), find(c2)
            if p1 != p2:
                parent[p1] = parent[p2]
                res += cost
        
        final = set()
        for i in range(1, N):
            pi = find(i)
            if pi not in final:
                final.add(pi)
            if len(final) > 1:
                return -1
        return res

__________________________________________________________________________________________________

__________________________________________________________________________________________________
