__________________________________________________________________________________________________
sample 648 ms submission
class Solution:
    def canReorderDoubled(self, A: List[int]) -> bool:
        c = collections.Counter(A)
        for x in sorted(c, key=abs):
            if c[x] > c[2 * x]:
                return False
            c[2 * x] -= c[x]
        return True
__________________________________________________________________________________________________
sample 14876 kb submission
class Solution:
    def canReorderDoubled(self, A: List[int]) -> bool:
        pos = dict()
        neg = dict()
        zer = 0
        for a in A:
            if a > 0:
                if a in pos:
                    pos[a] = pos[a] + 1
                else:
                    pos[a] = 1
            elif a < 0:
                if a in neg:
                    neg[a] = neg[a] + 1
                else:
                    neg[a] = 1
            else:
                zer = zer + 1
        
        if zer % 2:
            return False
        
        k = list(pos.keys())
        k.sort()
        for i in k:
            if pos[i] > 0: 
                if (i * 2 in pos) and (pos[2 * i] >= pos[i]):
                    pos[2 * i] = pos[2 * i] - pos[i]
                else:
                    return False
        
        k = list(neg.keys())
        k.sort(reverse=True)
        for i in k:
            if neg[i] > 0: 
                if (i * 2 in neg) and (neg[2 * i] >= neg[i]):
                    neg[2 * i] = neg[2 * i] - neg[i]
                else:
                    return False        
        return True
__________________________________________________________________________________________________
