__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def readBinaryWatch(self, num: int) -> List[str]:
        out = []
        for i in range(12):
            for j in range(60):
                if bin(j).count('1') == num - bin(i).count('1'):
                    out.append("{}:{:02d}".format(i, j)) 
        return out                
__________________________________________________________________________________________________
sample 12940 kb submission
class Solution:
    def readBinaryWatch(self, num: int) -> List[str]:
        
        ans = []
        
        def bitCount( n ):
            # compute the number of 1s in the binary representation of n
            
            count = 0
            while n > 0:
                if n%2 == 1:
                    count += 1
                n = n >> 1
            
            return count
        
        def convert(H, M):
            # convert to string time 0<= H < 12 
            return str(H) + ":" + ( "0" if M < 10 else "" ) + str(M)
        
        
        for H in range(0, 12):
            for M in range(0, 60):
                if bitCount(H) + bitCount(M) == num:
                    ans.append( convert(H, M) )
        
        return ans
__________________________________________________________________________________________________
