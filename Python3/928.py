__________________________________________________________________________________________________
sample 1124 ms submission
from collections import defaultdict
class Solution:
    def minMalwareSpread(self, graph: List[List[int]], initial: List[int]) -> int:
        g = [set() for _ in range(len(graph))]
        #initial = set(initial)
        for i, connections in enumerate(graph):
            g[i] = {k for k, conn in enumerate(connections) if conn == 1 and k != i}

        def bfs(k):
            queue = initial[::]
            res = 0
            used = set(queue)
            for i in queue:
                if i == k:
                    continue
                res += 1
                for j in g[i]:
                    if j not in used:
                        queue.append(j)
                        used.add(j)
            return res
        #print(g)
        res, cnt = -1, float('inf')
        for i in sorted(initial):
            cand = bfs(i)
            #print(i, cand)
            if cand < cnt:
                res, cnt = i, cand
        return res
__________________________________________________________________________________________________
sample 15000 kb submission
class Solution:
    def minMalwareSpread(self, graph, initial):

        source = collections.defaultdict(list)

        initial.sort()

        #print(initial)

        for i_node in initial:
            q = collections.deque()
            q.append(i_node)
            visited = set(initial)

            while len(q):
                node = q.popleft()

                for other_node, conn in enumerate(graph[node]):
                    #print(other_node, conn, node)
                    if not conn:
                        continue
                    if other_node in visited:
                        continue

                    visited.add(other_node)
                    source[other_node].append(i_node)
                    q.append(other_node)

        #print(source)

        d = collections.defaultdict(int)
        for node, nodes_list in source.items():
            #print("nl", nodes_list)
            if len(nodes_list) == 1:
                d[nodes_list[0]] += 1


        #print("d", d)
        mmax = 0
        res = -1
        for node in d:
            if d[node] > mmax:
                res = node
                mmax = d[node]
            elif d[node] == mmax:
                res = min(res, node)
                #print("res", res, mmax)

        #print("", res)

        if res == -1:
            return initial[0]
        return res
__________________________________________________________________________________________________
