__________________________________________________________________________________________________
sample 32 ms submission
"""
# Definition for a Node.
class Node:
    def __init__(self, val, neighbors):
        self.val = val
        self.neighbors = neighbors
"""
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        ### DFS
        mapping = {}
        def traverse(node):
            cn = Node(node.val,[])
            mapping[node] = cn
            for n in node.neighbors:
                if not n in mapping:
                    cnn = traverse(n)
                else:
                    cnn = mapping[n]
                cn.neighbors.append(cnn)
            return cn
        
        return traverse(node)
__________________________________________________________________________________________________
sample 13852 kb submission
"""
# Definition for a Node.
class Node:
    def __init__(self, val, neighbors):
        self.val = val
        self.neighbors = neighbors
"""
import collections
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if node is None:
            return None
        
        node_copy = Node(node.val, [])
        queue = collections.deque([node])
        visited = {}
        visited[node] = node_copy

        while len(queue) > 0:
            curr_node = queue.popleft()
            for neighbor in curr_node.neighbors:
                if visited.get(neighbor) is None:
                    new_neighbor = Node(neighbor.val, [])
                    queue.append(neighbor)
                    visited[neighbor] = new_neighbor
                    visited[curr_node].neighbors.append(new_neighbor)
                else:
                    visited[curr_node].neighbors.append(visited[neighbor])
        
        return node_copy
__________________________________________________________________________________________________
