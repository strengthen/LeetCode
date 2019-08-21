__________________________________________________________________________________________________
sample 352 ms submission
class Solution:
    def sumOfDistancesInTree(self, N: int, edges: List[List[int]]) -> List[int]:
        if not edges:
            return [0]
        
        result = [0] * N
        nodes = [set() for _ in range(N)]
        counts = [1] * N
        
        for i in range(len(edges)):
            nodes[edges[i][0]].add(edges[i][1])
            nodes[edges[i][1]].add(edges[i][0])
            
        result[0] = self._get_counts_and_distances(nodes, 0, counts, None)
        self._get_result(nodes, 0, counts, result, None)
        
        return result
        
    def _get_counts_and_distances(self, nodes, index, counts, parent):
        dis = 0
        count = 0
        for node in nodes[index]:
            if node == parent:
                continue
                
            dis += self._get_counts_and_distances(nodes, node, counts, index)
            dis += counts[node]
            counts[index] += counts[node]
            
        return dis
        
    def _get_result(self, nodes, index, counts, ans, parent):
        if parent is not None:
            ans[index] = ans[parent] - counts[index] + counts[0] - counts[index]
        
        for node in nodes[index]:
            if node == parent:
                continue
            self._get_result(nodes, node, counts, ans, index)
__________________________________________________________________________________________________
sample 356 ms submission
class Solution:
    def sumOfDistancesInTree(self, N: int, edges: List[List[int]]) -> List[int]:
        if not edges:
            return [0]
        
        result = [0] * N
        nodes = [set() for _ in range(N)]
        counts = [1] * N
        
        for i in range(len(edges)):
            nodes[edges[i][0]].add(edges[i][1])
            nodes[edges[i][1]].add(edges[i][0])
            
        result[0] = self._get_counts_and_distances(nodes, 0, counts, None)
        self._get_result(nodes, 0, counts, result, None)
        
        return result
        
    def _get_counts_and_distances(self, nodes, index, counts, parent):
        dis = 0
        for node in nodes[index]:
            if node == parent:
                continue
            dis += self._get_counts_and_distances(nodes, node, counts, index)
            dis += counts[node]
            counts[index] += counts[node]
            
        return dis
        
    def _get_result(self, nodes, index, counts, ans, parent):
        if parent is not None:
            ans[index] = ans[parent] - counts[index] + counts[0] - counts[index]
        
        for node in nodes[index]:
            if node == parent:
                continue
            self._get_result(nodes, node, counts, ans, index)
__________________________________________________________________________________________________
