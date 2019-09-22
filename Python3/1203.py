__________________________________________________________________________________________________
sample 492 ms submission
class Solution:
    def sortItems(self, n: int, m: int, group: List[int], beforeItems: List[List[int]]) -> List[int]:
        cnt = 0
        groups = collections.defaultdict(list)
        for i, g in enumerate(group):
            if g == -1:
                group[i] = cnt + m
                cnt += 1
            groups[group[i]].append(i)
        degrees = [0] * (m + cnt)
        graphs = collections.defaultdict(set)
        follows = collections.defaultdict(list)
        for v, befores in enumerate(beforeItems):
            for u in befores:
                if group[u] != group[v]:
                    degrees[group[v]] += 1
                    follows[group[u]].append(group[v])
                else:
                    graphs[group[u]].add((u, v))
        frees = []
        for i in range(cnt + m):
            if degrees[i] == 0:
                frees.append(i)
        # print(group)
        # print(frees)
        # print(degrees)
        # print(follows)
        group_seq = []
        while frees:
            node = frees.pop()
            group_seq.append(node)
            for nei in follows[node]:
                degrees[nei] -= 1
                if degrees[nei] == 0:
                    frees.append(nei)
        if len(group_seq) != m + cnt:
            return []
        ans = []
        for gidx in group_seq:
            if len(groups[gidx]) == 1:
                ans.append(groups[gidx].pop())
            else:
                eles = groups[gidx]
                edges = graphs[gidx]
                degrees = {e : 0 for e in eles}
                follows = collections.defaultdict(set)
                for u, v in edges:
                    degrees[v] += 1
                    follows[u].add(v)
                frees = []
                for e in eles:
                    if degrees[e] == 0:
                        frees.append(e)
                seq = []
                while frees:
                    node = frees.pop()
                    seq.append(node)
                    for nei in follows[node]:
                        degrees[nei] -= 1
                        if degrees[nei] == 0:
                            frees.append(nei)
                if len(seq) == len(eles):
                    ans.extend(seq)
                else:
                    return []
        return ans
__________________________________________________________________________________________________
from collections import defaultdict

class Solution(object):
    def sortItems(self, n, m, group, beforeItems):
        """
        :type n: int
        :type m: int
        :type group: List[int]
        :type beforeItems: List[List[int]]
        :rtype: List[int]
        """
        def sort_func(gg,indegree):
            res = []
            while len(indegree) > 0:
                temp = dict(indegree)
                pop_node = [i for i in temp.keys() if temp[i] == 0]
                for i in pop_node:
                    for j in gg[i]:
                        if j in temp:
                            temp[j] -= 1
                    res.append(i)
                    del (temp[i])
                if len(temp) > 0 and temp == indegree:
                    return -1
                indegree = temp
            return res
                    
        
        aggregate = defaultdict(list)
        cur = -1
        group_map = {}
        
        for i in range(n):
            if group[i]==-1:
                aggregate[cur].append(i)
                group_map[i] = cur
                cur-=1
            else:
                aggregate[group[i]].append(i)
                group_map[i] = group[i]
            
        gg = defaultdict(list)
        gf = defaultdict(list)
        print("start")
        for i in range(n):
            if len(beforeItems[i])>0:
                for j in beforeItems[i]:
                    if group_map[j]!=group_map[i]:
                        gg[group_map[j]].append(group_map[i])
                        gf[group_map[i]].append(group_map[j])
        indegree = {k:len(gf[k]) for k in aggregate.keys()}
        res = sort_func(gg,indegree)
        if res==-1:
            return []
        print(res)
        
        
        final_res = []
        for ii in res:
            innernode = aggregate[ii]
            gg = defaultdict(list)
            gf = defaultdict(list)
            
            for i in innernode:
                if len(beforeItems[i])>0:
                    for j in beforeItems[i]:
                        if group_map[j]==group_map[i]:
                            gg[j].append(i)
                            gf[i].append(j)
                
            indegree = {k:len(gf[k]) for k in innernode}
            res = sort_func(gg,indegree)
            if res==-1:
                return []
            else:
                final_res+=res
        return final_res
__________________________________________________________________________________________________
