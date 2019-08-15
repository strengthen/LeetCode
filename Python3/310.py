__________________________________________________________________________________________________
sample 248 ms submission
class Solution:
    def new_graph_dict(self, edges, n):
        g = {} # O(len(edges)) space
        for i in range(n): # O(n) time
            g[i] = []
        for u, v in edges: # O(len(edges)) time
            g[u].append(v)
            g[v].append(u)
        return g
    
    def height(self, root, g):
        # depth first search
        q = [root]
        heights = {root: 0}
        seen = set([root])
        while len(q) > 0:
            a = q.pop()
            if a in g:
                kids = g[a]
                for k in kids:
                    if k in seen:
                        continue
                    else:
                        seen.add(k)
                    q.append(k)
                    heights[k] = heights[a] + 1
        ans = -1
        for k in heights:
            v = heights[k]
            ans = max(ans, v)
        return ans
    
    def soln_1(self, n, edges):
        if len(edges) == 0 or n <= 1:
            return [0]
        cur_height = None
        cur_roots = []
        g = self.new_graph_dict(edges, n)
        for root in range(n):
            h = self.height(root, g)
            if cur_height is None or h < cur_height:
                cur_roots = [root]
                cur_height = h
            elif h == cur_height:
                cur_roots.append(root)
        return cur_roots
    
    def new_leaves(self, g):
        return set([v for v in g if len(g[v]) == 1])
    
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n <= 1:
            return [0]
        g = [[] for i in range(n)] # O(len(edges)) space, O(n) time
        for u, v in edges: # O(len(edges)) time
            g[u].append(v)
            g[v].append(u)
        leaves = [v for v in range(n) if len(g[v]) == 1]
        while n > 2:
            n -= len(leaves)
            next_leaves = []
            for v in leaves:
                
                g[g[v][0]].remove(v)
                if len(g[g[v][0]]) == 1:
                    next_leaves.append(g[v][0])
            leaves = next_leaves
        return leaves
__________________________________________________________________________________________________
sample 15904 kb submission
class Solution:
    def findMinHeightTrees(self, n: int, edges):
        if n == 0:
            return []
        if n == 1:
            return [0]
        dic = [[] for _ in range(n)]
        for i in range(len(edges)):
            dic[edges[i][0]].append(edges[i][1])
            dic[edges[i][1]].append(edges[i][0])
        #print(dic)
        queue = []
        for key in range(len(dic)):
            if len(dic[key]) == 1:
                queue.append(key)
        remain = n
        while queue:
            newQueue = []
            #print(queue, dic)
            if remain == 1 or remain == 2:
                break
            for q in queue:
                t = dic[q][0]
                dic[t].remove(q)
                if len(dic[t]) == 1:
                    newQueue.append(t)

            remain -= len(queue)
            queue = newQueue
        return queue
__________________________________________________________________________________________________
