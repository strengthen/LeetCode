__________________________________________________________________________________________________
sample 156 ms submission
class Solution:
    def intervalIntersection(self, A, B):
        a, b, res = 0, 0, []
        while a < len(A) and b < len(B):
            if A[a][1] < B[b][0]:
                a += 1
            elif B[b][1] < A[a][0]:
                b += 1
            else:
                start, end = max(A[a][0], B[b][0]), min(A[a][1], B[b][1])
                if not res or res[-1][1] < start:
                    res.append([start, end])
                a += end == A[a][1]
                b += end == B[b][1]
        return res
__________________________________________________________________________________________________
sample 13576 kb submission
class Solution:
    def intervalIntersection(self, A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
        A = A + B
        A.sort(key=lambda x: x[0])
        n = len(A)
        result = []
        for i in range(1, n):
            if A[i - 1][1] >= A[i][0]:
                result.append([A[i][0], min(A[i - 1][1], A[i][1])])
            A[i][1] = max(A[i - 1][1], A[i][1])
        return result
__________________________________________________________________________________________________
