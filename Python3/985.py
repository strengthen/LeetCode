__________________________________________________________________________________________________
sample 560 ms submission
class Solution:
    def sumEvenAfterQueries(self, A: List[int], queries: List[List[int]]) -> List[int]:
        res = []
        cur = sum([a for a in A if a % 2 == 0])
        for v,i in queries:
            if A[i] % 2 == 0:
                if v%2 == 0:
                    cur += v
                else:
                    cur -= A[i]
            else:
                if v%2 == 0:
                    pass
                else:
                    cur += A[i] + v
            A[i] += v
            res.append(cur)
        return res
__________________________________________________________________________________________________
sample 17244 kb submission
class Solution:
    def sumEvenAfterQueries(self, A: List[int], queries: List[List[int]]) -> List[int]:
        S = sum(x for x in A if x % 2 == 0)
        ans = []

        for x, k in queries:
            if A[k] % 2 == 0: S -= A[k]
            A[k] += x
            if A[k] % 2 == 0: S += A[k]
            ans.append(S)

        return ans
__________________________________________________________________________________________________
