__________________________________________________________________________________________________
sample 60 ms submission
class UF:
    def __init__(self):
        self.d = {}
    
    def union(self, v, u):
        prev = v
        traversed = set()
        while(v in self.d):
            traversed.add(v)
            v = self.d[v]
        for t in traversed:
            self.d[t] = v
    
        while(u in self.d):
            traversed.add(u)
            u = self.d[u]
        for t in traversed:
            self.d[t] = u
        if(u == v):
            return False
        else:
            self.d[u] = v
            return True
            
    
    
class Solution:
    
    def findRedundantDirectedConnection(self, edges: List[List[int]]) -> List[int]:
        
        e1, e2, p = None, None, {}
        for i, e in enumerate(edges):
            if e[1] in p:
                e1, e2 = p[e[1]], i
                break
            p[e[1]] = i
        
        uf = UF()
        for i, e in enumerate(edges):
            if i == e2:
                continue
            if(not uf.union(e[0], e[1])):
                return edges[e1] if e1 != None else edges[i]
        return edges[e2]        
__________________________________________________________________________________________________
sample 13500 kb submission
class Solution:
    def findRedundantDirectedConnection(self, edges: List[List[int]]) -> List[int]:
        N = len(edges)
        
        parent = [0]*(N+1)
        
        roots = list(range(N+1))
        sizes = [1]*(N+1)
        def find(x):
            if roots[x]!= x:
                roots[x] = find(roots[x])
            return roots[x]
        
        def union(x,y):
            rx,ry = find(x),find(y)
            roots[ry] = rx
        
        cand1 = None
        cand2 = None
        for u,v in edges:
            if parent[v]!=0:
                cand1 = [parent[v],v] 
                cand2 = [u,v] 
                edges.remove([u,v])
            else:
                parent[v]=u
        for u,v in edges:
            if find(u) == find(v):
                return cand1 if cand1 else [u,v]
            union(u,v)
        return cand2
__________________________________________________________________________________________________
