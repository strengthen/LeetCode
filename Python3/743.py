__________________________________________________________________________________________________
sample 488 ms submission
class Solution:
    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
        graph = collections.defaultdict(dict)
        for (u, v, w) in times:
            graph[u][v] = w
        heap = [(0, K)]
        dist = {n: float("inf") for n in range(1, N+1)}
        dist[K] = 0
        visited = set()
        while len(visited) < N and heap:
            (time, node) = heapq.heappop(heap)
            visited.add(node)
            for (v, w) in graph[node].items():
                if time + w < dist[v]:
                    dist[v] = time + w
                    heapq.heappush( heap, (dist[v], v) )
        ans = max(dist.values())
        if ans < float("inf"):
            return ans
        return -1
__________________________________________________________________________________________________
sample 14404 kb submission
class Solution:
    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
        if len(times) < 0 or len(times[0]) < 0:
            return -1
        edges = collections.defaultdict(list)
        for u, v, w in times:
            edges[u].append((v,w))
        dist = {}        
        heap = [(0,K)]
        while heap:
            d, pos = heapq.heappop(heap) # the current node must have the shortest distance
            if pos in dist:
                continue
            dist[pos] = d
            for nei, w in edges[pos]:
                if nei not in dist:
                    heapq.heappush(heap, (d+w, nei))
        return max(dist.values()) if len(dist) == N else -1
__________________________________________________________________________________________________
