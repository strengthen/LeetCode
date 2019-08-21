__________________________________________________________________________________________________
sample 496 ms submission
class Solution:
    def loudAndRich(self, richer: List[List[int]], quiet: List[int]) -> List[int]:
        
        # construct an adjacency list where out[x] = [y_1, y_2, .., y_n] means x is richer than them
        out = dict()
        for edge in richer:
            if edge[0] not in out:
                out[edge[0]] = [edge[1]]
            else:
                out[edge[0]].append(edge[1])
        
        # starting from quietest person, to least quiet person
        n = len(quiet)
        
        quietper = [ (quiet[i], i) for i in range(n) ]
        quietper = sorted(quietper, key = lambda elem: elem[0])
        
        ans = [-1 for i in range(n) ]
        

        for _, per in quietper:
            q = [per]
            
            while len(q)>0:
                i = q.pop()
                
                # if ans[i] not updated, update ans[i], and put all its neighbors into queue,
                # otherwise skip this step
                if ans[i] == -1:
                    ans[i] = per
                    if i in out:
                        for neigh in out[i]:
                            if ans[neigh] == -1:
                                q.append(neigh)
        
        
        return ans
__________________________________________________________________________________________________
sample 504 ms submission
class Solution:
    def loudAndRich(self, richer: List[List[int]], quiet: List[int]) -> List[int]:
        dic = collections.defaultdict(list)
        for i in richer:
            dic[i[1]].append(i[0])
        self.res=[-1 for i in range(len(quiet))]
        def helper(i):
            if not dic[i]: return i
            cur = i
            for j in dic[i]:
                if self.res[j]==-1: 
                    self.res[j] = helper(j)
                if quiet[self.res[j]] < quiet[cur]: 
                    cur=self.res[j]
            return cur 
        
        for i in range(len(self.res)): 
            self.res[i] = helper(i)
        return self.res
__________________________________________________________________________________________________
