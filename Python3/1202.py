__________________________________________________________________________________________________
sample 856 ms submission
class Solution:
    def smallestStringWithSwaps(self, str: str, pairs: List[List[int]]) -> str:
        def dfs(char):
            if char not in visited:
                visited.add(char)
                for new in nei[char]:
                    dfs(new)
            
        nei, string, pool = collections.defaultdict(set), list(str), set()
        for p, q in pairs:
            nei[p].add(q)
            nei[q].add(p)
        for node in nei:
            if node not in pool:
                visited = set()
                dfs(node)
                pool |= visited
                for i, c in zip(sorted(visited), sorted([string[j] for j in visited])):
                    string[i] = c
        return "".join(string)
__________________________________________________________________________________________________
class Solution:
def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:

    # build graph
    graph = {}
    for node in range(len(s)):
        graph[node] =[]
    for u,v in pairs:
        graph[u].append(v)
        graph[v].append(u)

    position = {} # idx -> char
    for node in range(len(s)):
        if node not in position:
            idx = set()
            self.dfs(node, idx, graph) # get connected graph idx
            self.buildPos(s, idx, position) # map idx -> char by sort

    res = ''
    for node in range(len(s)):
        res += position[node]
    return res

def buildPos(self, s, idx, position):
    idx_list = list(idx)
    char_list = []
    for idx in idx_list:
        char_list.append(s[idx])
    idx_list.sort()
    char_list.sort()
    for i in range(len(idx_list)):
        position[idx_list[i]] = char_list[i]

def dfs(self, node, idx, graph):
    idx.add(node)
    for nei in graph[node]:
        if nei not in idx:
            self.dfs(nei, idx, graph)
__________________________________________________________________________________________________
