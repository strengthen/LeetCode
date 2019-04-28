__________________________________________________________________________________________________
class Solution:
     def isEscapePossible(self, blocked, source, target):
        blocked = set(map(tuple, blocked))
        seen = set()

        def dfs(x, y, target, step=0):
            if not (0 <= x < 10**6 and 0 <= y < 10**6) or (x, y) in blocked or (x, y) in seen: return False
            seen.add((x, y))
            if step > 20000 or [x, y] == target: return True
            return dfs(x + 1, y, target, step + 1) or \
                dfs(x - 1, y, target, step + 1) or \
                dfs(x, y + 1, target, step + 1) or \
                dfs(x, y - 1, target, step + 1)
        return dfs(source[0], source[1], target) and dfs(target[0], target[1], source)
__________________________________________________________________________________________________
class Solution:
     def isEscapePossible(self, blocked, source, target):
        blocked = {tuple(p) for p in blocked}

        def bfs(source, target):
            bfs, seen = [source], {tuple(source)}
            for x0, y0 in bfs:
                for i, j in [[0, 1], [1, 0], [-1, 0], [0, -1]]:
                    x, y = x0 + i, y0 + j
                    if 0 <= x < 10**6 and 0 <= y < 10**6 and (x, y) not in seen and (x, y) not in blocked:
                        if [x, y] == target: return True
                        bfs.append([x, y])
                        seen.add((x, y))
                if len(bfs) == 20000: return True
            return False
        return bfs(source, target) and bfs(target, source)
__________________________________________________________________________________________________
