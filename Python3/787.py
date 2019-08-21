__________________________________________________________________________________________________
sample 76 ms submission
class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, K: int) -> int:
        
        ''' 
        #### BFS #### 
              
        graph = self.build_graph(n, flights)
        from collections import deque 
        queue = deque([(src, 0)])
        min_price = sys.maxsize 
        
        for k in range(K+1):
            
            visited = {}
            while queue:
                city, price = queue.popleft()
                    
                for next_city, next_price in graph[city]:
                    if next_city == dst:
                        min_price = min(min_price, price + next_price)
                        
                    if next_city in visited:
                        visited[next_city] = min(visited[next_city], price + next_price)
                    else:
                        visited[next_city] = price + next_price
                    
            queue = deque([(k, v) for k, v in visited.items()]) 
            
        return min_price if min_price < sys.maxsize else -1 
        '''
        
        #### Dijkstra's ####
        
        graph = self.build_graph(n, flights) 
        import heapq
        queue = [(0, src, -1)] #(price, city, stop)
        visited = set()
        while queue:
            cur_price, cur_city, stop = heapq.heappop(queue)
            if cur_city == dst:
                return cur_price 
            if stop >= K:
                continue   
            if (cur_city, stop) in visited:
                continue 
            visited.add((cur_city, stop))                
            for next_city, price in graph[cur_city]:
                heapq.heappush(queue, (price + cur_price, next_city, stop + 1))
                
        return -1 
       
    

    def build_graph(self, n, flights):
        graph = {i: [] for i in range(n)}
        for src, dst, price in flights:
            graph[src].append((dst, price))
        return graph 
__________________________________________________________________________________________________
sample 13624 kb submission
from typing import List
import math

class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, K: int) -> int:
        edges = dict(zip(range(n), (dict() for _ in range(n))))
        for start, end, dist in flights:
            edges[start][end] = dist
        
        l_prev = {src: 0}
        l_next = dict()
        min_dist = math.inf
        for _ in range(K + 1):
            for node in l_prev:
                for next_ in edges[node]:
                    cur_dist = l_prev[node] + edges[node][next_]
                    l_next[next_] = min(l_next[next_] if next_ in l_next else math.inf, cur_dist)
                    if next_ == dst:
                        min_dist = min(min_dist, l_next[next_])
            l_prev, l_next = l_next, dict()
        return -1 if min_dist == math.inf else min_dist
__________________________________________________________________________________________________
