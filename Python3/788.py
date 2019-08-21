__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def rotatedDigits(self, N: int) -> int:
        digits = str(N)
        rNum = {0,1,2,5,6,8,9}
        gNum = {0,1,8}
        
        def count(n, flag):
            total = 0
            fDigit = int(n[0])
            for d in range(fDigit):
                if d not in rNum:
                    continue
                total += 7**(len(n)-1)
                if flag and d in gNum:
                    total -= 3**(len(n)-1)           
            if len(n)>1 and fDigit in rNum:
                if fDigit not in gNum:
                    flag = False
                total += count(n[1:], flag)
            if len(n)==1 and fDigit in rNum:
                if (flag==False) or fDigit not in gNum:
                    total += 1
            return total
                
        
        return count(digits, True)
__________________________________________________________________________________________________
sample 13112 kb submission
class Solution:
    def rotatedDigits(self, N: int) -> int:
        ans = 0
        for x in range(1, N + 1):
            s = str(x)
            ans += (all(d not in '347' for d in s)
                    and any(d in '2569' for d in s))
        return ans                    
__________________________________________________________________________________________________
