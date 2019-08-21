__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def customSortString(self, s: str, t: str) -> str:
      order, end = { c: i for i, c in enumerate(s) }, 100
      return "".join(sorted(t, key=lambda c: order.get(c, end)))
__________________________________________________________________________________________________
sample 12896 kb submission
class Solution:
    def customSortString(self, S: str, T: str) -> str:
        order = dict()
        i = 0
        while len(S) > 0:
            order[S[0]] = i
            i += 1
            S = S[1:]
        return "".join(sorted(T, key=lambda x : order[x] if x in order else 0))
__________________________________________________________________________________________________
