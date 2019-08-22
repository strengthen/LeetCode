__________________________________________________________________________________________________
sample 380 ms submission
from collections import deque
class Solution:
    def shortestBridge(self, A: List[List[int]]) -> int:
        height = len(A)
        width = len(A[0])
        visited = [[0]*width for i in range(height)]
        deq = deque()
        deq2 = deque()
        
        # Seek the queue with any island space
        for j in range(height):
            for i in range(width):
                if A[j][i] != 0:
                    deq.append(((i,j),0))
                    visited[j][i] = 1
                    break
            if deq:
                break
        
        while deq:
            pos, moves = deq.popleft()
            i,j = pos
            val = A[j][i]
            if val == 0:
                deq2.append((pos, 1))
            else:
                if j > 0 and visited[j-1][i] == 0:
                    deq.append(((i,j-1),moves))
                    visited[j-1][i] = 1
                if j < height-1 and visited[j+1][i] == 0:
                    deq.append(((i,j+1),moves))
                    visited[j+1][i] = 1
                if i > 0 and visited[j][i-1] == 0:
                    deq.append(((i-1,j),moves))
                    visited[j][i-1] = 1
                if i < width-1 and visited[j][i+1] == 0:
                    deq.append(((i+1,j),moves))
                    visited[j][i+1] = 1
                    
        print(deq2)
                    
        while deq2:
            pos, moves = deq2.popleft()
            i,j = pos
            val = A[j][i]
            if val == 1:
                return moves-1
            else:
                moves += 1
                if j > 0 and visited[j-1][i] == 0:
                    deq2.append(((i,j-1),moves))
                    visited[j-1][i] = 1
                if j < height-1 and visited[j+1][i] == 0:
                    deq2.append(((i,j+1),moves))
                    visited[j+1][i] = 1
                if i > 0 and visited[j][i-1] == 0:
                    deq2.append(((i-1,j),moves))
                    visited[j][i-1] = 1
                if i < width-1 and visited[j][i+1] == 0:
                    deq2.append(((i+1,j),moves))
                    visited[j][i+1] = 1
            
        return -1
__________________________________________________________________________________________________
sample 13308 kb submission
class Solution:
    def shortestBridge(self, A: List[List[int]]) -> int:
        if len(A) == 0 or len(A[0]) == 0:
            return 0
        
        m, n = len(A), len(A[0])
        
        queue = collections.deque()
        break_loop = False
        for a in range(m):
            for b in range(n):
                if A[a][b] == 1:
                    A[a][b] = 2
                    queue.append((a,b))
                    break_loop = True
                    break
            if break_loop:
                break
        
        dir_x = [-1,0,0,1]
        dir_y = [0,-1,1,0]
        boundary = collections.deque()
        while queue:
            x0,y0 = queue.popleft()
            for k in range(4):
                x = x0 + dir_x[k]
                y = y0 + dir_y[k]
                if 0 <= x < m and 0<= y < n:
                    if A[x][y] == 1:
                        A[x][y] = 2
                        queue.append((x,y))
                    elif A[x][y] == 0:
                        boundary.append((x,y))
                        A[x][y] = -1
                
        cnt = 0
        while boundary:
            cnt += 1
            size = len(boundary)
            for _ in range(size):
                x0,y0 = boundary.popleft()
                for k in range(4):
                    x = x0 + dir_x[k]
                    y = y0 + dir_y[k]
                    if 0 <= x < m and 0 <= y < n:
                        if A[x][y] == 1:
                            return cnt
                        elif A[x][y] == 0:
                            boundary.append((x,y))
                            A[x][y] = -1
            # end looping over this level
            
        
        return 0
__________________________________________________________________________________________________
