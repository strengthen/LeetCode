__________________________________________________________________________________________________
sample 336 ms submission
class Solution(object):
    def catMouseGame(self, graph):
        N=len(graph)
        f=collections.defaultdict(int)

        q=collections.deque([])
        branchs={}
        MOUSE,CAT=1,2
        
        for i in range(1,N):
            for j in range(2):
                q.append((0,i,j,MOUSE))
                q.append((i,i,j,CAT))
                f[0,i,j]=MOUSE
                f[i,i,j]=CAT
        
        for i in range(N):
            for j in range(1,N):
                branchs[i,j,0]=len(graph[i])
                branchs[i,j,1]=len(graph[j])-(0 in graph[j])
        
        while q:
            mouse,cat,turn,winner=q.popleft()
            if turn==0:
                for i in graph[cat]:
                    if i==0: continue
                    if f[mouse,i,1]==0:#cat moves
                        if winner==CAT:
                            f[mouse,i,1]=CAT
                            q.append((mouse,i,1,CAT))
                        else:
                            branchs[mouse,i,1]-=1
                            if branchs[mouse,i,1]==0:
                                f[mouse,i,1]=MOUSE
                                q.append((mouse,i,1,MOUSE))
            else:
                for i in graph[mouse]:
                    if f[i,cat,0]==0:
                        if winner==MOUSE:
                            f[i,cat,0]=MOUSE
                            q.append((i,cat,0,MOUSE))
                        else:
                            branchs[i,cat,0]-=1
                            if branchs[i,cat,0]==0:
                                f[i,cat,0]=CAT
                                q.append((i,cat,0,CAT))
        
        return f[1,2,0]
__________________________________________________________________________________________________
sample 416 ms submission
import functools

class Solution:
    @functools.lru_cache(maxsize=None)
    def dp(self, t: int, mouse: int, cat: int) -> int:
        if t > self.n:
            return 0
        if mouse == 0:
            return 1
        if mouse == cat:
            return 2
        if t % 2 == 0:
            draw = False
            for u in self.g[mouse]:
                state = self.dp(t + 1, u, cat) 
                if state == 1:
                    return 1
                if state == 0:
                    draw = True
            return 0 if draw else 2
        else:
            draw = False
            for u in self.g[cat]:
                if u != 0:
                    state = self.dp(t + 1, mouse, u)
                    if state == 2:
                        return 2
                    if state == 0:
                        draw = True
            return 0 if draw else 1
                
        
    
    def catMouseGame(self, graph: List[List[int]]) -> int:
        self.g = graph
        self.n = len(graph)
        return self.dp(0, 1, 2)
__________________________________________________________________________________________________
