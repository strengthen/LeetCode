__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def findComplement(self, num: int) -> int:
        li=list(str(bin(num)))
        li=li[2:]
        for i in range(len(li)):
            if li[i]=="0":
                li[i]="1"
            else:
                li[i]="0"
        k="".join(li)
        return int(k,2)
__________________________________________________________________________________________________
sample 12948 kb submission
class Solution:
    def findComplement(self, num: int) -> int:
        output=0
        mod=1
        while num != 0:
            if num & 1 == 0:
                output += mod
            mod <<=1
              
            num >>= 1
        
        return output
__________________________________________________________________________________________________
