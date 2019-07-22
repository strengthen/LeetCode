__________________________________________________________________________________________________
sample 124 ms submission
class Solution:
    def maxAbsValExpr(self, arr1: List[int], arr2: List[int]) -> int:
        ans = 0
        n = len(arr1)
        for a, b in (1, 1), (1, -1), (-1, -1), (-1, 1):
            mn = a * arr1[0] + b * arr2[0] + 0
            for i in range(n):
                cur = a * arr1[i] + b * arr2[i] + i
                ans = max(ans, cur - mn)
                mn = min(mn, cur)
        return ans
__________________________________________________________________________________________________
class Solution:
    def maxAbsValExpr(self, arr1: List[int], arr2: List[int]) -> int:
        n = len(arr1)
        rtn = 0
        for sign1 in [-1, 1]:
            for sign2 in [-1, 1]:
                b = []
                for i in range(n):
                    b.append(arr1[i] * sign1 + arr2[i] * sign2 + i)
                rtn = max(rtn, max(b) - min(b))
        return rtn
__________________________________________________________________________________________________
