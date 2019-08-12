__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def numDecodings(self, s: str) -> int:
        last = next_last = 1
        res = 0
        if s[0] == '0':
            return 0        
        if len(s) == 1:            return 1
        
        for i in range(1,len(s)):
            if s[i] == '0':
                if s[i - 1] >= '3' or s[i - 1] == '0':
                    return 0
                else:
                    res = next_last
            elif s[i-1] == '1' or (s[i- 1] == '2' and s[i] <= '6'):
                res = next_last + last
            else:
                res = last
            next_last = last
            last = res
                
        return res
__________________________________________________________________________________________________
sample 13008 kb submission
class Solution:
    def numDecodings(self, s: str) -> int:
        if not s or s[0] == "0":
            return 0

        numWays = [0] * (len(s) + 1)

        numWays[0] = 1
        if s[0] != "0":
            numWays[1] = 1

        for i in range(2, len(s) + 1):
            oneChar = int(s[i - 1])
            twoChar = int(s[i - 2:i])
            if 0 < oneChar < 10:
                numWays[i] += numWays[i - 1]
            if 9 < twoChar < 27:
                numWays[i] += numWays[i - 2]
        return numWays[-1]
__________________________________________________________________________________________________
