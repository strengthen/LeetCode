__________________________________________________________________________________________________
sample 108 ms submission
class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        N = len(board)
        # convert to 1 d
        bd = [0]
        cnt = 0
        for i in range(N-1,-1,-1):
            if cnt % 2 == 0:
                bd += board[i]
            else:
                bd += board[i][::-1]
            cnt += 1
        #print(bd)        
        #self.minCnt = float('inf')
        N2 = N*N
        queue = [1]
        move  = 0
        seen = set()
        seen.add(1)
        #print(bd)
        while queue:
            length = len(queue)
            move += 1
            for _ in range(length):
                val = queue.pop(0)
                for i in range(1,7):
                    tgt = val + i
                    if tgt == N2:     # ended first before checking snake 
                        return move
                    if tgt <= N2 and bd[tgt] != -1:
                        tgt = bd[tgt]
                    #print(tgt, seen)
                    if tgt not in seen:
                        queue.append(tgt)
                        seen.add(tgt)
                    if tgt == N2:
                        return move
        return -1
__________________________________________________________________________________________________
sample 112 ms submission
class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        X, flag, r = [], True, len(board)
        for i in range(r - 1, -1, -1):
            if flag:
                X.extend(board[i])
                
            else:
                X.extend(board[i][::-1])
            
            flag = not flag
        
        n = r * len(board[0])
        Y, Z = [(0, 0)], [0] + [n for _ in range(n - 1)]
        
        while Y:
            i, m = Y.pop(0)
            if Z[i] == m:
                for j in range(i + 1, i + 7):
                    if X[j] != -1:
                        j = X[j] - 1
                    
                    if j == n - 1:
                        return m + 1
                    
                    if Z[j] == -1 or Z[j] > m + 1:
                        Z[j] = m + 1
                        Y += [(j, m + 1)]
        
        return -1
__________________________________________________________________________________________________
