__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        return self.usingGraph(equations, values, queries)
    
    def usingGraph(self, equations, values, queries):
        g = collections.defaultdict(list)
        N = len(equations)
        for i in range(N):
            g[equations[i][0]].append([equations[i][1], values[i]])
            g[equations[i][1]].append([equations[i][0], 1 / values[i]])
            
        def dfs(a, b):
            if not a in g or not b in g:
                return -1.0
            if a == b:
                return 1.0
            seen.add(a)
            for c, v in g[a]:
                if not c in seen:
                    tmp = dfs(c, b)
                    if tmp == -1.0:
                        continue
                    return v * tmp
            return -1.0
        
        
        res = []
        for q in queries:
            seen = set()
            res.append(dfs(q[0], q[1]))
        return res        
__________________________________________________________________________________________________
sample 12968 kb submission
class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        root = {}
        dist = {}
        res = []
        size = len(values)
        for i in range(size):
            p0 = self.find(root, dist, equations[i][0])
            p1 = self.find(root, dist, equations[i][1])
            root[p0] = p1
            dist[p0] = values[i] * dist[equations[i][1]] / dist[equations[i][0]]
        for query in queries:
            if query[0] not in root or query[1] not in root:
                res.append(-1.0)
                continue
            r0 = self.find(root, dist, query[0])
            r1 = self.find(root, dist, query[1])
            if r0 != r1:
                res.append(-1.0)
                continue
            res.append(dist[query[0]]/dist[query[1]])
        return res
    
    def find(self, root, dist, node):
        if node not in root:
            root[node] = node
            dist[node] = 1.0
            return node
        if root[node] == node:
            return node
        last_parent = root[node]
        parent = self.find(root, dist, last_parent)
        root[node] = parent
        dist[node] = dist[node] * dist[last_parent]
        return parent        
__________________________________________________________________________________________________
