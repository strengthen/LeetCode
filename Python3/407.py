__________________________________________________________________________________________________
sample 164 ms submission
class Solution:
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        if not heightMap or not heightMap[0]:
            return 0
        m = len(heightMap)
        n = len(heightMap[0])
        
        heap = []
        seen = [[False] * n for _ in range(m)]
        
        # Puts the edges on the heap
        for i in range(m):
            heap.append( (heightMap[i][0], i, 0) )
            heap.append( (heightMap[i][n - 1], i, n - 1) )
            seen[i][0] = True
            seen[i][n - 1] = True
        for j in range(n):
            heap.append( (heightMap[0][j], 0, j) )
            heap.append( (heightMap[m - 1][j], m - 1, j) )
            seen[0][j] = True
            seen[m - 1][j] = True
        heapq.heapify(heap)
        
        area = 0
        while heap:
            h, i, j = heapq.heappop(heap)
            if h > heightMap[i][j]:
                area += h - heightMap[i][j]
                
            if i > 0 and not seen[i - 1][j]:
                heapq.heappush(heap, (max(h, heightMap[i - 1][j]), i - 1, j))
                seen[i - 1][j] = True
            if i + 1 < m and not seen[i + 1][j]:
                heapq.heappush(heap, (max(h, heightMap[i + 1][j]), i + 1, j))
                seen[i + 1][j] = True
            if j > 0 and not seen[i][j - 1]:
                heapq.heappush(heap, (max(h, heightMap[i][j - 1]), i, j - 1))
                seen[i][j - 1] = True
            if j + 1 < n and not seen[i][j + 1]:
                heapq.heappush(heap, (max(h, heightMap[i][j + 1]), i, j + 1))
                seen[i][j + 1] = True
                
        return area
__________________________________________________________________________________________________
sample 14168 kb submission
class Solution:
    def trapRainWater(self, heightMap):
        """
        :type heightMap: List[List[int]]
        :rtype: int
        """
        if not any(heightMap):
            return 0
        m, n = len(heightMap), len(heightMap[0])
        boundaries = []
        for i, row in enumerate(heightMap):
            for j, val in enumerate(row):
                if i in (0, m - 1) or j in (0, n - 1):
                    boundaries.append((val, i, j))
                    heightMap[i][j] = -1
        heapq.heapify(boundaries)
        ans = 0
        while boundaries:
            height, i, j = heapq.heappop(boundaries)
            for newi, newj in (i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1):
                if 0 <= newi < m and 0 <= newj < n and heightMap[newi][newj] != -1:
                    ans += max(0, height - heightMap[newi][newj])
                    heapq.heappush(boundaries, (max(height, heightMap[newi][newj]), newi, newj))
                    heightMap[newi][newj] = -1
        return ans      
__________________________________________________________________________________________________
