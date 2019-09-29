__________________________________________________________________________________________________
sample 308 ms submission
class Solution:
    def minimumMoves(self, grid: List[List[int]]) -> int:
        n = len(grid)
        for row in grid:
            row.append(1)
        grid.append([1] * (n+1))
        source = (0, 0, True)
        sink = (n-1, n-2, True)
        seen = set()
        queue = collections.deque()
        queue.append((source, 0))
        while queue:
            node, k = queue.popleft()
            if node == sink:
                return k
            x, y, h = node
            nbrs = [
                (x+1, y, h),
                (x, y+1, h),
                (x, y, not h)
            ]
            for nbr in nbrs:
                if nbr in seen:
                    continue
                bx, by, bh = nbr
                if grid[bx][by] == 1:
                    continue
                if bh and grid[bx][by+1] == 1:
                    continue
                if not bh and grid[bx+1][by] == 1:
                    continue
                if (x, y) == (bx, by) and grid[x+1][by+1] == 1:
                    continue
                seen.add(nbr)
                queue.append((nbr, k+1))
        return -1
__________________________________________________________________________________________________
320ms
class Solution:
def minimumMoves(self, grid: List[List[int]]) -> int:
    n = len(grid)
    start = (0, 0, 0, 1)
    end = (n - 1, n - 2, n - 1, n - 1)
    curr_level = {start}
    moves = 0
    visited = set()
    while curr_level:
        next_level = set()
        for pos in curr_level:
            visited.add(pos)
            r1, c1, r2, c2 = pos
            if c1 + 1 < n and grid[r1][c1+1] == 0 and c2 + 1 < n and grid[r2][c2+1] == 0:
                if (r1, c1 + 1, r2, c2 + 1) not in visited:
                    next_level.add((r1, c1 + 1, r2, c2 + 1))
            if r1 + 1 < n and grid[r1+1][c1] == 0 and r2 + 1 < n and grid[r2+1][c2] == 0:
                if (r1 + 1, c1, r2 + 1, c1) not in visited:
                    next_level.add((r1 + 1, c1, r2 + 1, c2))
            if r1 == r2 and c2 == c1 + 1 and r1 + 1 < n and grid[r1+1][c1] + grid[r1+1][c1+1] == 0 :
                if (r1, c1, r1 + 1, c1) not in visited:
                    next_level.add((r1, c1, r1 + 1, c1))
            if c1 == c2 and r2 == r1 + 1 and c1 + 1 < n and grid[r1][c1+1] + grid[r1+1][c1+1] == 0:
                if (r1, c1, r1, c1 + 1) not in visited:
                    next_level.add((r1, c1, r1, c1 + 1))
        if end in next_level:
            return moves + 1
        curr_level = next_level
        moves += 1
    return -1
__________________________________________________________________________________________________
sample 332 ms submission
class Solution:
    def minimumMoves(self, grid: List[List[int]]) -> int:
        # BFS
        n = len(grid)
        frontier = collections.deque([((0, 0), (0, 1))])
        step = 0
        visited = {((0, 0), (0, 1))}
        target = ((n-1, n-2), (n-1, n-1))
        while frontier:
            sz = len(frontier)
            for _ in range(sz):
                node = frontier.popleft()
                if node == target:
                    return step
                (x1, y1), (x2, y2) = node
                if x1 == x2: # horizontal
                    # move right
                    if y2 + 1 < n and grid[x1][y2 + 1] == 0 and ((x2, y2), (x2, y2 + 1)) not in visited:
                        visited.add(((x2, y2), (x2, y2 + 1)))
                        frontier.append(((x2, y2), (x2, y2 + 1)))
                    # move down
                    if x1 + 1 < n and grid[x1 + 1][y1] == 0 and grid[x1 + 1][y2] == 0 and ((x1 + 1, y1), (x1 + 1, y2)) not in visited:
                        visited.add(((x1 + 1, y1), (x1 + 1, y2)))
                        frontier.append(((x1 + 1, y1), (x1 + 1, y2)))
                    # rotate clockwise
                    if x1 + 1 < n and grid[x1 + 1][y1] == 0 and grid[x1 + 1][y2] == 0 and ((x1, y1), (x1 + 1, y1)) not in visited:
                        visited.add(((x1, y1), (x1 + 1, y1)))
                        frontier.append(((x1, y1), (x1 + 1, y1)))
                if y1 == y2: # vertical
                    # move right
                    if y2 + 1 < n and grid[x1][y1 + 1] == 0 and grid[x2][y2 + 1] == 0 and ((x1, y1 + 1), (x2, y2 + 1)) not in visited:
                        visited.add(((x1, y1 + 1), (x2, y2 + 1)))
                        frontier.append(((x1, y1 + 1), (x2, y2 + 1)))
                    # move down
                    if x2 + 1 < n and grid[x2 + 1][y2] == 0 and ((x2, y2), (x2 + 1, y2)) not in visited:
                        visited.add(((x2, y2), (x2 + 1, y2)))
                        frontier.append(((x2, y2), (x2 + 1, y2)))
                    if y2 + 1 < n and grid[x1][y1 + 1] == 0 and grid[x2][y2 + 1] == 0 and ((x1, y1), (x1, y1 + 1)) not in visited:
                        visited.add(((x1, y1), (x1, y1 + 1)))
                        frontier.append(((x1, y1), (x1, y1 + 1)))
            step += 1
        return -1
