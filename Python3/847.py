__________________________________________________________________________________________________
sample 104 ms submission
import heapq

class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
  
        # solution 2
        n = len(graph)
        goal = (1 << n) - 1
        curs = []
        past = set()
        for i in range(n):
            curs.append([0, i, 1<<i])
            past.add((i, 1<<i))
            
        while curs:
            temp = []
            for c, i, s in curs:
                if s == goal: return c
                for j in graph[i]:
                    next_s = s | (1 << j)
                    if (j, next_s) not in past:
                        past.add((j, next_s))
                        temp.append([c+1, j, next_s])
            curs = temp
        return -1 
__________________________________________________________________________________________________
sample 112 ms submission
class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        memo, final, q, steps = set(), (1 << len(graph)) - 1, [(i, 1 << i) for i in range(len(graph))], 0
        while True:
            new = []
            for node, state in q:
                if state == final: return steps
                for v in graph[node]:
                    if (state | 1 << v, v) not in memo:
                        new.append((v, state | 1 << v))
                        memo.add((state | 1 << v, v))
            q = new
            steps += 1
__________________________________________________________________________________________________
