__________________________________________________________________________________________________
sample 80 ms submission
class Solution:
    def movesToChessboard(self, board: List[List[int]]) -> int:
        N = len(board)
        rp, cp = board[0], [x[0] for x in board]    #<1>
        rn, cn = [(x+1)%2 for x in rp], [(x+1)%2 for x in cp]   #<2>
        
        def core(is_row): # <3>
            count = errs = 0
            for i in range(N):
                if is_row: line, pos, neg = board[i], rp, rn
                else: line, pos, neg = [x[i] for x in board], cp, cn
                
                if line == pos:
                    count+=1 # <4>
                    if i%2==1: errs+=1  # <A>
                elif line == neg:
                    if i%2==0: errs+=1  # <A>
                else: return -1 # <5>
            if count > math.ceil(N/2) or count < math.floor(N/2): return -1 # <6>
            cand1 = math.inf if errs%2==1 else errs//2  # <B>
            cand2 = math.inf if (N-errs)%2==1 else (N-errs)//2  # <B>
            return min(cand1, cand2)# if min(cand1, cand2) != math.inf else -1
                    
        row_ans = core(True)
        if row_ans == -1: return -1
        col_ans = core(False)
        if col_ans == -1: return -1
        return row_ans + col_ans
__________________________________________________________________________________________________
sample 88 ms submission
class Solution:
    def movesToChessboard(self, board: List[List[int]]) -> int:
        n = len(board)
        row = collections.Counter(map(tuple,board))  
        column = collections.Counter(zip(*board))

    #    print(row)
    #    print(column)
        result = 0
        for x in (row,column):
            if len(x) != 2: return -1
            if sorted(x.values()) != [n//2, (n+1)//2]: return -1

            x1, x2 = x.keys()
            for a, b in zip(x1, x2):
                if a^b == 0: return -1

            start = []
            if n%2:
                count = [0,0]
                for key in x.keys():
                    if x[key] == (n+1)//2: longer = key
                for i in longer:
                    count[i] += 1
                if count[0] > count[1]: start = [0]
                else: start = [1]
            else: start = [0,1]
            #print(start)


            if n%2:
                want = start[0]
                for i in longer:
                    if i != want: result += 1
                    want = 1-want
            else:
                min_val = 2**31
                for j in start:
                    temp = 0
                    want = j
                    for i in x1:
                        if i != want: temp += 1
                        want = 1-want
                    min_val = min(min_val,temp)
                result += min_val

        return result//2
__________________________________________________________________________________________________
