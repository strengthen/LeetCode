__________________________________________________________________________________________________
sample 56 ms submission
class Solution:
    def bagOfTokensScore(self, tokens: List[int], P: int) -> int:
        if len(tokens) == 0:
            return 0
        tokens = list(sorted(tokens))
        if tokens[0] > P:
            return 0
        s = 0
        i=0
        j=len(tokens)-1
        while i <= j:
            if P >= tokens[i]:
                P -= tokens[i]
                i += 1
                s += 1
            elif P < tokens[i] and (P + tokens[j]) >= tokens[i]:
                P = P + tokens[j] - tokens[i]
                i += 1
                j -= 1
            else:
                break
        return s    
__________________________________________________________________________________________________
sample 13216 kb submission
from collections import deque 
class Solution:
    def bagOfTokensScore(self, tokens: List[int], P: int) -> int:
        tokens.sort()
        points = ans = 0
        que = deque(tokens)
        while que and (points or P >=que[0]):
            while que and P >= que[0]:
                P -= que.popleft()
                points+=1
            ans = max(ans,points)
            if points and que:
                P+= que.pop()
                points-=1
        return ans 
__________________________________________________________________________________________________
