__________________________________________________________________________________________________
sample 40 ms submission
from collections import defaultdict
class MySet:
    def __init__(self, s):
        self.my_set = s
class Solution:
    def equationsPossible(self, equations):
        if len(equations) == 0:
            return True
        d = defaultdict(list)
        for s in equations:
            if '==' in s:
                if d[s[0]] == [] and d[s[-1]] == []:
                    l = MySet(set([s[0],s[-1]]))
                    d[s[0]] = d[s[-1]] = l
                elif d[s[0]] == []:
                    d[s[-1]].my_set.add(s[0])
                    d[s[0]] = d[s[-1]]
                elif d[s[-1]] == []:
                    d[s[0]].my_set.add(s[-1])
                    d[s[-1]] = d[s[0]]
                else:
                    d[s[0]].my_set = d[s[0]].my_set|d[s[-1]].my_set
                    d[s[-1]].my_set = d[s[0]].my_set
        for s in equations:
            if '!=' in s:
                if s[0] == s[-1]:
                    return False
                if (d[s[-1]] != [] and s[0] in d[s[-1]].my_set) or (d[s[0]] != [] and s[-1] in d[s[0]].my_set):
                    return False
        return True
__________________________________________________________________________________________________
sample 44 ms submission
class Solution:
    def equationsPossible(self, equations: List[str]) -> bool:
        p = [_ for _ in range(128)] # p: parent        
        def find(a):
            if a != p[a]: p[a] = find(p[a])
            return p[a]
        
        for s in [s for s in equations if '!' not in s]:
            p[find(ord(s[0]))] = p[find(ord(s[-1]))]
            
        for s in [s for s in equations if '!' in s]:
            if find(ord(s[0])) == find(ord(s[-1])) or s[0] == s[-1]: 
                return False  
            
        return True
__________________________________________________________________________________________________
