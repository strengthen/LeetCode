__________________________________________________________________________________________________
Runtime: 1156 ms
Memory Usage: 16 MB
class Solution(object):
	def maxDistance(self, grid):
		N = len(grid)
		maxnum = float('inf')
		dist = {(i, j): maxnum for i in range(N) for j in range(N)}
		seen = set()
		queue = []
		for i in range(N): 
			for j in range(N): 
				if grid[i][j] == 1:
					queue.append((i, j))
					dist[i, j] = 0

		res = -1
		while queue:
			i, j = queue.pop(0)

			for k, l in [(i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)]:
				if k < 0 or k >= N or l < 0 or l >= N or grid[k][l] != 0:
					continue

				dist[k, l] = min(dist[k, l], dist[i, j] + abs(i - k) + abs(j - l))
				res = max(res, dist[k, l])
                
				if (k, l) not in seen:
					seen.add((k, l))
					queue.append((k, l))

		return res
__________________________________________________________________________________________________

__________________________________________________________________________________________________
