__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        code = [ord(t) - ord('a') for t in target]
        code = [(c // 5, c % 5) for c in code]
        res = ""
        code = [(0,0)] + code
        
        def path(step1, step2, num, res):
            if num > 0:
                res += step1 * num 
            elif num < 0:
                res += step2 * (-num)
            return res
        
        for i in range(1, len(code)):
            v = code[i][0] - code[i-1][0]
            h = code[i][1] - code[i-1][1]
            if code[i] == (5,0):
                res = path('R', 'L', h, res)
                res = path('D', 'U', v, res)
            else:
                res = path('D', 'U', v, res)
                res = path('R', 'L', h, res)
            res += '!'
        return res
__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        s,i,j,n='',0,0,ord('a')
        for c in target:
            t=ord(c)-n
            ii,jj=t//5,t%5
            if ii>i:
                if jj>j: s+='R'*(jj-j)
                else: s+='L'*(j-jj)
                s+='D'*(ii-i)
            else:
                s+='U'*(i-ii)
                if jj>j: s+='R'*(jj-j)
                else: s+='L'*(j-jj)
            s+='!'
            i,j=ii,jj
        return s
__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"]
        adjust = ord('a')
        words_per_set = 5
        current_r=0
        current_c=0
        result=""
        
        def is_exits(r,c):
            try:
                board[r][c]
                return True
            except Exception:
                return False
            
        for t_c in target:
            adj_ord_c=ord(t_c)-adjust
            target_r = adj_ord_c // words_per_set
            target_c = adj_ord_c % words_per_set
            
            while (target_r != current_r) or (target_c != current_c):
                if current_r > target_r and is_exits(current_r-1,current_c):
                    result+="U"
                    current_r -= 1
                    continue
                if current_r < target_r and is_exits(current_r+1,current_c):
                    result+="D"
                    current_r += 1
                    continue
                if current_c > target_c and is_exits(current_r,current_c-1):
                    result+="L"
                    current_c -= 1
                    continue
                if current_c < target_c and is_exits(current_r,current_c+1):
                    result+="R"
                    current_c += 1
                    continue
            
            result += "!"
            
        
        return result