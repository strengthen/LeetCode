class Solution:
    def orderlyQueue(self, S: str, K: int) -> str:
        s = ''.join(sorted(S))
        if K == 1:
            mi = S
            for i in range(len(S)):
                S = S[1:]+S[0]
                mi = min(mi,S)
            return mi
        else:
            return s            
