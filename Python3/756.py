__________________________________________________________________________________________________
sample 32 ms submission
from collections import defaultdict

class Solution:
    def pyramidTransition(self, bottom: str, allowed: List[str]) -> bool:
        graph = defaultdict(set)
        for x in allowed:
            graph[x[:2]].add(x[-1])
        
        bot = list(map(set, bottom))
        # print(graph)
    
        for i in reversed(range(len(bottom)-1)):
            # print(bot)
            top = []
            for j in range(i+1):
                product = set()
                for x in bot[j]:
                    for y in bot[j+1]:
                        product |= graph[x+y]
                        
                if not product:
                    return False
                top.append(product)
            bot = top
        
        # print(bot)
        return bot and bot[0]
__________________________________________________________________________________________________
sample 14060 kb submission
class Solution:
    def pyramidTransition(self, bottom: str, allowed: List[str]) -> bool:
        import collections
        dic=collections.defaultdict(list)
        
        for w in allowed:
            dic[w[:2]].append(w[-1])
            
        def dfs(candi):
            if len(candi)==1:
                return True
 
            
            # 
            next_candi=['']
            for i in range(len(candi)-1):
                if dic[candi[i:i+2]]=='':
                    return False
                mid=[]
                for c in  dic[candi[i:i+2]]:
                    for can in next_candi:
                        mid.append(can+c)
                next_candi=mid[:]
                
                
            for up_layer in next_candi:
                if dfs(up_layer):
                    return True
            return False
        
        return dfs(bottom)
__________________________________________________________________________________________________
