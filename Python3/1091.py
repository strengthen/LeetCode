__________________________________________________________________________________________________
class Solution:
    def shortestPathBinaryMatrix(self, A: List[List[int]]) -> int:
        if A[0][0]: return -1
        dq = collections.deque([(0, 0)])
        seen = {(0, 0)}
        step = 1
        n = len(A)
        while dq:
            sz = len(dq)
            for _ in range(sz):
                x, y = dq.popleft()
                for dx, dy in ((0, 1), (0, -1), (1, 0), (-1, 0), (1, 1), (-1, 1), (-1, -1), (1, -1)):
                    xx, yy = x + dx, y + dy
                    if 0 <= xx < n and 0 <= yy < n and A[xx][yy] == 0 and (xx, yy) not in seen:
                        seen.add((xx, yy))
                        if (xx, yy) == (n - 1, n - 1): return step + 1
                        dq.append((xx, yy))
            step += 1
        return -1
__________________________________________________________________________________________________

__________________________________________________________________________________________________
