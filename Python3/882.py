__________________________________________________________________________________________________
sample 504 ms submission
class Solution:
    def reachableNodes(self, edges: List[List[int]], M: int, N: int) -> int:
        '''
        single source weighted graph for shortest distance - dijkstra
        
        re exam each edge
        p-----q
        
        from p side we can reach x nodes, from q size we can reach y nodes then we know how many nodes 
        can be reached on this edge
        '''
        g= collections.defaultdict(dict)
        for i, j, w in edges:
            g[i][j] = w
            g[j][i] = w
            
        solved = [False]*N
        dist = [math.inf]*N
        dist[0] = 0
        
        heap = [[0, 0]]
        while heap:
            d, i = heapq.heappop(heap)
            
            if solved[i]:
                continue
                
            solved[i] = True
            for j in g[i]:
                if not solved[j]:
                    w = dist[i] + g[i][j] + 1 # w+1 steps to reach the other original node
                    if w<=M and w<dist[j]:
                        dist[j] = w
                        heapq.heappush(heap, (dist[j], j))
                 
        # print(dist)
        count = 0
        
        # original nodes
        for i in range(N):
            if dist[i]<=M:
                count += 1
        
        # virtual nodes on edges
        for i, j, w in edges:
            left = max(0, M - dist[i])
            right = max(0, M - dist[j])
            count += min(left+right, w)
    
        return count        
__________________________________________________________________________________________________
sample 524 ms submission
from heapq import heappush as hpush
from heapq import heappop as hpop

class Solution:
    def reachableNodes(self, edges: List[List[int]], M: int, N: int) -> int:
        '''Create graph'''
        graph = {}
        for vetex in range(N):
            graph[vetex] = {}
        
        for vetex1, vetex2, distance in edges:
            graph[vetex1][vetex2] = distance
            graph[vetex2][vetex1] = distance
        
        '''initialize heap queue'''
        heap_queue = []
        move, src = 0, 0
        hpush(heap_queue, (move, src))
        
        '''initialize others'''
        visited = set()
        count = 0
        
        while heap_queue:
            move, vetex = hpop(heap_queue)
            
            '''Use all the step, break'''
            if move > M:
                break
            
            '''This node has been visited, pass'''
            if vetex in visited:
                continue
            
            
            visited.add(vetex) 
            count += 1
            
            for neighbor in graph[vetex]:
                weight = graph[vetex][neighbor]
                next_move = move + weight + 1
                
                '''
                    if the neighboring vetex has been visited,
                    we check if the remaining step (M - move) is enough 
                    to cover all nodes between vetex and neighbor
                    Later on, we'll see we only save nodes that have not been
                    visited. 
                '''
                if neighbor in visited:
                    count = count + min(M - move, graph[vetex][neighbor])
                
                else:
                    if next_move > M:
                        count = count + (M - move) 
                        '''Save nodes that are only not been visited.'''
                        graph[neighbor][vetex] -= (M - move)
                    
                    else:
                        count = count + weight
                        '''
                            Save nodes that are only not been visited.
                            Here, all have been visited, so updated to 0
                        '''
                        graph[neighbor][vetex] = 0
                        '''Update next_move as move'''
                        hpush(heap_queue, (next_move, neighbor))
        
        return count
__________________________________________________________________________________________________
