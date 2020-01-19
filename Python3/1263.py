__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def minPushBox(self, grid: List[List[str]]) -> int:
        m, n, g = len(grid), len(grid[0]), collections.defaultdict(list)
        for i in range(m):
            for j in range(n):
                g[grid[i][j]] += [complex(i, j)]
        def f(b, s): 
            nonlocal time
            time += 1
            boxToTarget = b - target
            return (abs((boxToTarget).real) + abs((boxToTarget).imag) + s, abs(boxToTarget), time)
        player, box, target, time = *g['S'], *g['B'], *g['T'], 1
        floor = {player, target, box, *g['.']}
        alphaStarQueue = [(f(box, 1), 1, player, box)]
        directions, visited = (1, 1j, -1, -1j), set()
        low = dict.fromkeys(floor, 0)
        dfn = low.copy()
        count = 0
        index = {}
        def tarjan(currIndex, parentIndex):
            nonlocal count
            count += 1
            dfn[currIndex] = low[currIndex] = count
            index[count] = currIndex
            for direction in directions:
                nextIndex = currIndex + direction
                if nextIndex in floor and nextIndex != parentIndex:
                    if not low[nextIndex]:
                        tarjan(nextIndex, currIndex)
                    low[currIndex] = min(low[currIndex], low[nextIndex])
        tarjan(box, -1)
        for currIndex in floor:
            connect = [currIndex]
            while dfn[connect[-1]] != low[connect[-1]]:
                connect.append(index[low[connect[-1]]])
            for w in connect[: -2]:
                low[w] = low[connect[-1]]
        while alphaStarQueue:
            _, steps, currPlayer, currBox = heapq.heappop(alphaStarQueue)
            for direction in directions:
                nextPlayer, nextBox = currBox - direction, currBox + direction
                if nextBox in floor \
                    and nextPlayer in floor \
                        and (nextPlayer, currBox) not in visited \
                            and low[currPlayer] == low[nextPlayer]:
                    if nextBox == target:
                        return steps
                    heapq.heappush( alphaStarQueue, (f(nextBox, steps + 1), steps + 1, currBox, nextBox))
                    visited.add((nextPlayer, currBox))
        return -1
__________________________________________________________________________________________________
sample 48 ms submission
class Solution:
    def minPushBox(self, grid: List[List[str]]) -> int:
        n,m=len(grid),len(grid[0])
        bcc=[[set() for j in range(m)] for i in range(n)]
        low=[[0]*m for i in range(n)]
        dfn=[[0]*m for i in range(n)]
        T,cnt,st=0,0,[]
        def dfs(i,j):
            nonlocal T,cnt
            if not (0<=i<n and 0<=j<m) or grid[i][j]=='#':
                return -1
            elif dfn[i][j]>0:
                return 0
            st.append((i,j))
            T+=1
            low[i][j]=dfn[i][j]=T
            for x,y in [(i+1,j),(i-1,j),(i,j+1),(i,j-1)]:
                temp=dfs(x,y)
                if temp==-1:
                    continue
                elif temp==0:
                    low[i][j]=min(low[i][j],dfn[x][y])
                    continue
                if low[x][y]>=dfn[i][j]:
                    cnt+=1
                    while True:
                        a,b=st.pop()
                        bcc[a][b].add(cnt)
                        if (a,b)==(x,y):
                            break
                    bcc[i][j].add(cnt)
                low[i][j]=min(low[i][j],low[x][y])
        for i in range(n):
            for j in range(m):
                if grid[i][j]!='#' and dfn[i][j]==0:
                    dfs(i,j)
                if grid[i][j]=='S':
                    sx,sy=i,j
                elif grid[i][j]=='T':
                    tx,ty=i,j
                elif grid[i][j]=='B':
                    bx,by=i,j
        q0,visited=[(sx,sy)],[[0]*m for i in range(n)]
        visited[sx][sy]=1
        while q0:
            temp=[]
            for x,y in q0:
                for px,py in [(x+1,y),(x-1,y),(x,y+1),(x,y-1)]:
                    if 0<=px<n and 0<=py<m and grid[px][py] in '.T' and visited[px][py]==0:
                        visited[px][py]=1
                        temp.append((px,py))
            q0=temp
        q=[(bx,by,x,y) for x,y in [(bx+1,by),(bx-1,by),(bx,by+1),(bx,by-1)] if visited[x][y]]
        visited,ans=set(q),0
        while q:
            temp=[]
            for x1,y1,x2,y2 in q:
                #print(x1,y1,x2,y2)
                if (x1,y1)==(tx,ty):
                    return ans
                x1,y1,x2,y2=x1*2-x2,y1*2-y2,x1,y1
                if not (0<=x1<n and 0<=y1<m) or grid[x1][y1]=='#':
                    continue
                for px,py in [(x1+1,y1),(x1-1,y1),(x1,y1+1),(x1,y1-1)]:
                    #print(px,py)
                    if (0<=px<n and 0<=py<m) and (grid[px][py]!='#') and (bcc[px][py]&bcc[x2][y2]) and ((x1,y1,px,py) not in visited):
                        nxt=x1,y1,px,py
                        visited.add(nxt)
                        temp.append(nxt)
            q,ans=temp,ans+1
        return -1
__________________________________________________________________________________________________
