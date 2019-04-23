__________________________________________________________________________________________________
56ms
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        i = 0
        arr = [''] * numRows
        reverse = False
        for char in s:
            arr[i] += char
            if reverse:
                i -= 1
                if i < 0:
                    i += 2
                    reverse = False
            else:
                i += 1
                if i == numRows:
                    i -= 2
                    reverse = True
        return ''.join(arr)
__________________________________________________________________________________________________
60ms
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows==1:
            return s
        rows=['']*min(len(s),numRows)
        godown=False
        currow=0
        for c in s:
            rows[currow] +=c
            if currow==0 or currow==numRows-1:
                godown=not godown
            if godown:
                currow +=1               
            else:
                currow -=1
        return ''.join(rows)
__________________________________________________________________________________________________
68ms
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        ans = [''] * numRows
        pos = 0
        while pos < len(s):
            for i in range(numRows):
                ans[i] = ans[i] + s[pos]
                pos += 1
                if pos == len(s):
                    break
            if pos==len(s):
                break
            for i in range(1,numRows-1):
                ans[numRows - i - 1] += s[pos]
                pos += 1
                if pos == len(s):
                    break
        l = ''
        for i in ans:
            l += i
        return l
__________________________________________________________________________________________________
12264 kb
class Solution:
    def convert(self, s: 'str', numRows: 'int') -> 'str':
        if numRows == 1:
            return s
        distance = numRows - 2
        
        out = ''
        for row in range(numRows):
                
            if row == 0 or row == numRows - 1:
                # No interior guys
                delta = distance + numRows
        
                i = row
                while(i < len(s)):
                    out += s[i]
                    i += delta

            else:
                delta = distance + numRows 

                i = row
                while(i < len(s)):
                    out += s[i]
                    
                    # Also add an element
                    if i + 2*numRows  - 2*row - 2 < len(s):
                        out += s[i + 2*numRows  - 2*row - 2]
                    
                    i += delta
        return out
__________________________________________________________________________________________________
12324 kb
class Solution:
    def convert(self, s: 'str', numRows: 'int') -> 'str':
        down = False
        table = [''] * numRows
        curr_row = 0
        if numRows == 1:
            return s 
        
        for c in s:
            table[curr_row] += c
            if curr_row == 0 or curr_row == numRows - 1:
                down = not down
            
            if down:
                curr_row += 1 
            else:
                curr_row -= 1

        return ''.join(table)
__________________________________________________________________________________________________
