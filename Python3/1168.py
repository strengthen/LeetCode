__________________________________________________________________________________________________
class Solution:
    def minCostToSupplyWater(self, n: int, w: List[int], p: List[List[int]]) -> int:
        
        def find(x):
            if x != up[x]:
                up[x] = find(up[x])
            return up[x]

        def union(x, y, cost):
            a, b = find(x), find(y)
            if a != b and max(exp[b], exp[a]) > cost:
                up[a] = b
                sav = max(exp[b], exp[a]) - cost
                exp[b] = min(exp[b], exp[a])
                return sav
            return 0
        
        p.sort(key=lambda x: x[2])        
        up = [i for i in range(n + 1)]
        exp = [0] + w
        ret = sum(w)
        for u, v, c in p:
            ret -= union(u, v, c)
        return ret

__________________________________________________________________________________________________

__________________________________________________________________________________________________
