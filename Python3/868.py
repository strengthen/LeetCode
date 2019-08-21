__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def binaryGap(self, N: int) -> int:
        abin = str(bin(N))[3:]
        length = 0
        max_len = 0
        for char in abin:
            length += 1
            if int(char):
                max_len = max(max_len, length)
                length = 0
        return max_len
__________________________________________________________________________________________________
sample 12892 kb submission
class Solution:
    def binaryGap(self, N: int) -> int:
        t = '{0:0b}'.format(N)
        d = 0
        md = 0
        in_pair = False
        
        for i in t:
            if in_pair:
                d += 1
                
                if i == '1':
                    in_pair = False
                    md = max(d, md)
                    d = 0
                    
            if i == '1' and not in_pair:
                in_pair = True
                d = 0
            
        return md
__________________________________________________________________________________________________
