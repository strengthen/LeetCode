__________________________________________________________________________________________________
sample 132 ms submission
class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        count = 0
        nodes = {}
        def find(u):
            if nodes[u] != u:
                nodes[u]=find(nodes[u])
            return nodes[u]
        for x,y in stones:
            u,v = x,~y
            if u in nodes and v in nodes:
                u=find(u)
                v=find(v)
                if u!=v:
                    count-=1
                    nodes[v]=u
            elif u in nodes:
                nodes[v]=nodes[u]
            elif v in nodes:
                nodes[u]=nodes[v]
            else:
                nodes[v]=nodes[u]=u
                count+=1
        return len(stones) - count
__________________________________________________________________________________________________
sample 13300 kb submission
class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        seen = set()
        d_s = dict()
        def update_ds(node, new_node):
            while d_s[node] != node:
                # Path compression
                d_s[node] = d_s[d_s[node]]
                node = d_s[node]
            d_s[node] = new_node
                
        def find(coor):
            d_s[coor] = coor
            x, y = coor
            for stone in seen:
                if stone[0] == coor[0] or stone[1] == coor[1]:
                    update_ds(stone, coor)
            seen.add(coor)
            
        for coor in stones:
            tup = tuple(coor)
            find(tup)
            
        cnt = 0
        for k, v in d_s.items():
            if k == v:
                cnt += 1
        return len(stones) - cnt
__________________________________________________________________________________________________
