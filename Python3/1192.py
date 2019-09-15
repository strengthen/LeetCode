__________________________________________________________________________________________________
from collections import defaultdict
class Solution:
    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        nbrs = defaultdict(set)
        for i, j in connections:
            nbrs[i].add(j)
            nbrs[j].add(i)
        endpoints = [i for i in range(n) if len(nbrs[i]) == 1]
        ans = []
        while endpoints:
            curr = set()
            for i in endpoints:
                if not nbrs[i]: continue
                j = nbrs[i].pop()
                ans.append([i, j])
                nbrs[j].discard(i)
                if len(nbrs[j]) == 1:
                    curr.add(j)
            endpoints = curr
        return ans
__________________________________________________________________________________________________
sample 2504 ms submission
class Solution:
    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        nei, ans = collections.defaultdict(set), set()
        for i, j in connections:
            nei[i].add(j)
            nei[j].add(i)
        pool = {n for n in nei if len(nei[n]) == 1}
        while pool:
            temp = set()
            for p in pool:
                new = list(nei[p])[0]
                ans.add((min(new, p), max(new, p)))
                nei[new].remove(p)
                if len(nei[new]) == 1:
                    temp.add(new)
            pool = temp.copy()
        return list(ans)
__________________________________________________________________________________________________
sample 2808 ms submission
class Solution:
    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        graph=collections.defaultdict(set)
        for x,y in connections:
            graph[x].add(y)
            graph[y].add(x)
        
        def bridgeUtil(u, visited, parent, low, disc, time): 

            # Mark the current node as visited and print it 
            visited[u]= True

            # Initialize discovery time and low value 
            disc[u] = time[0]
            low[u] = time[0]
            time[0]+=1

            #Recur for all the vertices adjacent to this vertex 
            ans=[]
            for v in graph[u]: 
                # If v is not visited yet, then make it a child of u 
                # in DFS tree and recur for it 
                if visited[v] == False : 
                    parent[v] = u 
                    find = bridgeUtil(v, visited, parent, low, disc,time) 
                    ans.extend(find)

                    # Check if the subtree rooted with v has a connection to 
                    # one of the ancestors of u 
                    low[u] = min(low[u], low[v]) 


                    ''' If the lowest vertex reachable from subtree 
                    under v is below u in DFS tree, then u-v is 
                    a bridge'''
                    if low[v] > disc[u]: 
                        ans.append([u,v])


                elif v != parent[u]: # Update low value of u for parent function calls. 
                    low[u] = min(low[u], disc[v]) 
            return ans



        visited = [False] * (n) 
        disc = [float("Inf")] * (n) 
        low = [float("Inf")] * (n) 
        parent = [-1] * (n) 

        # Call the recursive helper function to find bridges 
        # in DFS tree rooted with vertex 'i' 
        ans=[]
        time=[0]
        for i in range(n): 
            if visited[i] == False: 
                ans.extend(bridgeUtil(i, visited, parent, low, disc,time))
        return ans