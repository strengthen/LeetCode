__________________________________________________________________________________________________
sample 508 ms submission
class Solution:
    def cutOffTree(self, forest):
        # Add sentinels (a border of zeros) so we don't need index-checks later on.
        forest.append([0] * len(forest[0]))
        for row in forest:
            row.append(0)

        # Find the trees.
        trees = [(height, i, j)
                 for i, row in enumerate(forest)
                 for j, height in enumerate(row)
                 if height > 1]

        # Can we reach every tree? If not, return -1 right away.
        queue = [(0, 0)]
        reached = set()
        for i, j in queue:
            if (i, j) not in reached and forest[i][j]:
                reached.add((i, j))
                queue += (i+1, j), (i-1, j), (i, j+1), (i, j-1)
        if not all((i, j) in reached for (_, i, j) in trees):
            return -1

        # Distance from (i, j) to (I, J).
        def distance(i, j, I, J):
            now, soon = [(i, j)], []
            expanded = set()
            manhattan = abs(i - I) + abs(j - J)
            detours = 0
            while True:
                if not now:
                    now, soon = soon, []
                    detours += 1
                i, j = now.pop()
                if (i, j) == (I, J):
                    return manhattan + 2 * detours
                if (i, j) not in expanded:
                    expanded.add((i, j))
                    for i, j, closer in (i+1, j, i < I), (i-1, j, i > I), (i, j+1, j < J), (i, j-1, j > J):
                        if forest[i][j]:
                            (now if closer else soon).append((i, j))

        # Sum the distances from one tree to the next (sorted by height).
        trees.sort()
        return sum(distance(i, j, I, J) for (_, i, j), (_, I, J) in zip([(0, 0, 0)] + trees, trees))
__________________________________________________________________________________________________
sample 13684 kb submission
class Solution:
    def cutOffTree(self, forest: List[List[int]]) -> int:
        trees = sorted((v, r, c) for r, row in enumerate(forest)
                       for c, v in enumerate(row) if v > 1)
        sr = sc = ans = 0
        for _, tr, tc in trees:
            d = self.hadlocks(forest, sr, sc, tr, tc)
            if d < 0: return -1
            ans += d
            sr, sc = tr, tc
        return ans
    
    def hadlocks(self, forest, sr, sc, tr, tc):
        R, C = len(forest), len(forest[0])
        processed = set()
        deque = collections.deque([(0, sr, sc)])
        while deque:
            detours, r, c = deque.popleft()
            if (r, c) not in processed:
                processed.add((r, c))
                if r == tr and c == tc:
                    return abs(sr-tr) + abs(sc-tc) + 2*detours
                for nr, nc, closer in ((r-1, c, r > tr), (r+1, c, r < tr),
                                       (r, c-1, c > tc), (r, c+1, c < tc)):
                    if 0 <= nr < R and 0 <= nc < C and forest[nr][nc]:
                        if closer:
                            deque.appendleft((detours, nr, nc))
                        else:
                            deque.append((detours+1, nr, nc))
        return -1
__________________________________________________________________________________________________
