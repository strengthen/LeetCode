__________________________________________________________________________________________________
sample 56 ms submission
class Solution:
    def diStringMatch(self, S: str) -> List[int]:
        top = len(S)
        bottom = 0
        total = []
        for order in S:
            if order == "I":
                total.append(bottom)
                bottom = bottom + 1
            else:
                total.append(top)
                top = top - 1
        total.append(top)
        return total
__________________________________________________________________________________________________
sample 14064 kb submission
class Solution:
    def diStringMatch(self, S: str) -> List[int]:
        r = [0]
        m = 0
        M = 0
        for s in S:
            if s == 'D':
                r.append(m - 1)
                m -= 1
            else:
                r.append(M + 1)
                M += 1
        return [i + abs(m) for i in r]
__________________________________________________________________________________________________
