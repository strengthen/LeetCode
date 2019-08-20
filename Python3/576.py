__________________________________________________________________________________________________
sample 84 ms submission
class Solution:    
    def findPaths(self, m: int, n: int, N: int, i: int, j: int) -> int:
        counter = [0] * (m*n)
        ans = 0
        positions = [0] * (m*n)
        positions[i*n+j] = 1
        counter[i*n+j] = 1   
        
        for k in range(N):
            p = positions.copy()
            for l in range(len(positions)):
                if p[l] == 1:
                    row = l // n
                    line = l % n
                    if line == 0:
                        ans += counter[l]
                    else:
                        positions[l-1] = 1
                        counter[l-1] += counter[l]
                        
                    if line == n-1:
                        ans += counter[l]
                    else:
                        positions[l+1] = 1
                        counter[l+1] += counter[l]
                        
                    if row == 0:
                        ans += counter[l]
                    else:
                        positions[l-n] = 1
                        counter[l-n] += counter[l]
                        
                    if row == m-1:
                        ans += counter[l]
                    else:
                        positions[l+n] = 1
                        counter[l+n] += counter[l]
                    counter[l] = 0
                    positions[l] = 0
                
                
        return ans%(10**9+7)	
__________________________________________________________________________________________________
sample 13156 kb submission
class Solution:
    def findPaths(self, R, C, N, sr, sc):
        MOD = 10**9 + 7
        nxt = [[0] * C for _ in range(R)]
        nxt[sr][sc] = 1

        ans = 0
        for time in range(N):
            cur = nxt
            nxt = [[0] * C for _ in range(R)]
            for r, row in enumerate(cur):
                for c, val in enumerate(row):
                    for nr, nc in ((r-1, c), (r+1, c), (r, c-1), (r, c+1)):
                        if 0 <= nr < R and 0 <= nc < C:
                            nxt[nr][nc] += val
                            nxt[nr][nc] %= MOD
                        else:
                            ans += val
                            ans %= MOD

        return ans
__________________________________________________________________________________________________
