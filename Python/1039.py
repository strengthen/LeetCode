__________________________________________________________________________________________________
import functools
class Solution:
    def minScoreTriangulation(self, A: List[int]) -> int:
        @functools.lru_cache(None)
        def solve(labels):
            if len(labels) == 3:
                return functools.reduce(operator.mul, labels)
            res = math.inf
            n = len(labels)
            for i in range(2, n - 1):
                left = solve(labels[:i + 1])
                right = solve((labels[0],) + labels[i:])
                res = min(res, left + right)
            return min(res, labels[-1] * labels[0] * labels[1] + solve(labels[1:]))
            
        return solve(tuple(A))
            
__________________________________________________________________________________________________

__________________________________________________________________________________________________
