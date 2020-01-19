__________________________________________________________________________________________________
sample 12 ms submission
class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        for i in range(1,n):
            if "0" not in str(i) and '0' not in str(n-i) :
                return [i,n-i]
__________________________________________________________________________________________________
sample 16 ms submission
class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        
        for i in range(1,n):
            b=n-i # printing the list 
            s=i+b
            if '0' not in str(b) and '0' not in str(i):
                if s==n:
                    return([i,b])
                    break
__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        x=n
        l=[]
        c=0
        while x!=0:
            x=x-1
            c=c+1
            l.append(str(x))
            l.append(str(c))
            s="".join(l)
            if(s.find('0')==-1):
                break
            l.pop()
            l.pop()
        r=[]
        r.append(c)
        r.append(x)
        return r