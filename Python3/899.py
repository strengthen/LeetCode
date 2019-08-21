__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def orderlyQueue(self, S: str, K: int) -> str:
        # Simulate
        if K == 0:
            return S
        if K == 1:
            idxes = collections.defaultdict(list)
            for i, ch in enumerate(S):
                idxes[ch].append(i)
            first = min(S)
            best = -1
            curmin = "z" * len(S)
            for start in idxes[first]:
                if S[start:] < curmin:
                    curmin = S[start:]
                    best = start
            return S[best:] + S[:best]
        return "".join(sorted(S))
__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def orderlyQueue(self, S: str, K: int) -> str:
        if K > 1:
            return ''.join(sorted(S))
        else:
            minS = S
            for i in range(len(S)):
                S = S[1:] + S[0]
                if S < minS: minS = S
        return minS
        
__________________________________________________________________________________________________
