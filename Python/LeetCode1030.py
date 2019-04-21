__________________________________________________________________________________________________
256ms
class Solution:
    def allCellsDistOrder(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        def dist(point):
            pi, pj = point
            return abs(pi - r0) + abs(pj - c0)
        points = [(i, j) for i in range(R) for j in range(C)]
        return sorted(points, key=dist)
        
__________________________________________________________________________________________________
260ms
class Solution:
    def allCellsDistOrder(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        
        
        mat = [[i, j] for i in range(R) for j in range(C)]
        
        return sorted(mat, key = lambda x: abs(r0 - x[0]) + abs(c0 - x[1]))
__________________________________________________________________________________________________
288ms
class Solution:
    def allCellsDistOrder(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        return sorted([[r, c] for r in range(R) for c in range(C)], key=lambda x : (abs(x[0] - r0) + abs(x[1] - c0)))
__________________________________________________________________________________________________
332ms
class Solution:
    def allCellsDistOrder(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        vis = set([(r0, c0)])
        res = []
        bfs = [(r0, c0)]
        for i, j in bfs:
            res.append([i, j])
            for a, b in [(i-1,j),(i+1,j),(i,j+1),(i,j-1)]:
                if (0 <= a < R) and (0 <= b < C) and (a, b) not in vis:
                    vis.add((a, b))
                    bfs.append((a, b))
        return res
__________________________________________________________________________________________________
352ms
class Solution:
    def allCellsDistOrder(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        x, y = r0 if 0 <= r0 < R else 0 if r0 < 0 else R - 1, c0 if 0 <= c0 < C else 0 if c0 < 0 else C - 1
        visited, ans, stack = {(x, y)}, [], [[x, y]]
        while stack:
            ans.extend(stack)
            temp = []
            for i, j in stack:
                for x1, y1 in [[i - 1, j], [i + 1, j], [i, j - 1], [i, j + 1]]:
                    if 0 <= x1 < R and 0 <= y1 < C and (x1, y1) not in visited:
                        temp.append([x1, y1])
                        visited.add((x1, y1))
            stack[:] = temp
        return ans
__________________________________________________________________________________________________