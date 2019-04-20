class Solution:
    def longestArithSeqLength(self, A: List[int]) -> int:
        d = collections.defaultdict(dict)
        n = len(A)
        res = 1
        for i in range(n):
            for j in range(i):
                v = A[i] - A[j]
                # the default length is 1
                if v not in d[j]: d[j][v] = 1
                if v not in d[i]: d[i][v] = 0
                d[i][v] = max(d[i][v] ,d[j][v] + 1)
                res = max(res, d[i][v])
        return res