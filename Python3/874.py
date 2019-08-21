__________________________________________________________________________________________________
sample 376 ms submission
class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        x = 0
        y = 0
        h = 'n'
        ans = 0
        obstacleSet = set(map(tuple, obstacles))
        for c in commands:
            if c > 0:
                if h =='n': 
                    for i in range(c):
                        if (x,y+1) not in obstacleSet:
                            y += 1
                        else:
                            break
                elif h == 's': 
                    for i in range(c):
                        if (x,y-1) not in obstacleSet:
                            y -= 1
                        else:
                            break
                elif h == 'w': 
                    for i in range(c):
                        if (x-1,y) not in obstacleSet:
                            x -= 1
                        else:
                            break
                elif h == 'e': 
                    for i in range(c):
                        if (x+1,y) not in obstacleSet:
                            x += 1
                        else:
                            break
                            
                ans = max(ans, x*x + y*y)
                
            elif c == -1:
                if h =='n': h = 'e'
                elif h == 's': h = 'w'
                elif h == 'w': h = 'n'
                elif h == 'e': h = 's'
            elif c == -2:
                if h =='n': h = 'w'
                elif h == 's': h = 'e'
                elif h == 'w': h = 's'
                elif h == 'e': h = 'n'
        
        return ans
__________________________________________________________________________________________________
sample 17284 kb submission
class Solution:
    def robotSim(self, commands, obstacles):
        dx, dy = [0, 1, 0, -1], [1, 0, -1, 0]
        obstacles = set(map(tuple, obstacles))
        x, y, di, ans = 0, 0, 0, 0
        for c in commands:
            if c == -1: di = (di + 1) % 4
            elif c == -2: di = (di - 1) % 4
            else:
                for _ in range(c):
                    if (x + dx[di], y + dy[di]) not in obstacles:
                        x += dx[di]
                        y += dy[di]
                    else: break
                if x * x + y * y > ans: ans = x * x + y * y
        return ans
__________________________________________________________________________________________________
