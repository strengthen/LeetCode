__________________________________________________________________________________________________
sample 184 ms submission
def is_bipartite(graph, node_index, marked, color):
    marked[node_index] = True
    for next_node_index in graph[node_index]:
        if not marked[next_node_index]:
            color[next_node_index] = (not color[node_index])
            bipart = is_bipartite(graph, next_node_index, marked, color)
            if not bipart:
                return False
        elif color[next_node_index] == color[node_index]:
            return False
    return True
            
    


class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        marked = [False]*len(graph)
        color = [None]*len(graph)
        color[0] = False
        for node in range(len(graph)):
            if not marked[node]:
                color[node] = False
                two_color = is_bipartite(graph, node, marked, color)
                if not two_color:
                    return False
        return True
__________________________________________________________________________________________________
sample 12984 kb submission
class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        
        nodeTeam = {}
        
        for i in range(len(graph)):
            if i not in nodeTeam:
                team = True
                nodeTeam[i] = team
                stack = collections.deque(graph[i])
                n = len(stack)

                while stack:
                    team = team ^ True
                    n = len(stack)
                    for j in range(n):
                        node = stack.popleft()
                        if node in nodeTeam:
                            if nodeTeam[node] != team:
                         #print(node, nodeTeam, team)
                                return False
                        else:
                            nodeTeam[node] = team
                            stack.extend(graph[node])
        return True
__________________________________________________________________________________________________
