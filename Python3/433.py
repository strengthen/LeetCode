__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def minMutation(self, s: str, e: str, bank: List[str]) -> int:
        setb = set(bank)
        q = collections.deque()
        q.append([s,s,0])
        while q:
            prev,cur,steps = q.popleft()
            if cur==e: return steps 
            for b in bank: 
                if b!=prev and b in setb and sum([s1!=s2 for s1,s2 in zip(b,cur)])==1:
                    q.append([cur,b,steps+1])
                    setb.remove(b)
        return -1
__________________________________________________________________________________________________
sample 12948 kb submission
class Solution:
    def minMutation(self, start: str, end: str, bank: List[str]) -> int:
        bankSet = set(bank)
        if end not in bankSet:
            return -1
        queue = [[start]]
        visit = set()
        best = float('inf')
        while queue:
            path = queue.pop(0)
            gen = path[-1]
            if gen==end:
                best = min(best,len(path)-1)
            for i in range(len(gen)):
                for j in "ACGT":
                    new_gen = gen[:i]+j+gen[i+1:]
                    if new_gen in bankSet and new_gen not in visit:
                        queue.append(path + [new_gen])
                        visit.add(new_gen)
        if best==float('inf'):
            return -1
        else:
            return best
__________________________________________________________________________________________________
