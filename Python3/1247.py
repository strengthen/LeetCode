__________________________________________________________________________________________________
sample 12 ms submission
class Solution:
    def minimumSwap(self, s1: str, s2: str) -> int:
        temp = []
        for i in range(len(s1)):
            if s1[i] != s2[i]:
                temp.append({"x": 0, "y": 1}[s1[i]])
        if len(temp) % 2: return -1
        countx = temp.count(0)
        if countx % 2:
            return len(temp) // 2 + 1
        else:
            return len(temp) // 2
__________________________________________________________________________________________________
sample 16 ms submission
class Solution:
    def minimumSwap(self, s1: str, s2: str) -> int:
        a=s1.count('x')
        b=s1.count('y')
        c=s2.count('x')
        d=s2.count('y')
        
        if((a+c)%2==0 and (b+d)%2==0):
            xy=0
            yx=0
            for i in range(0,len(s1)):
                if(s1[i]!=s2[i]):
                    if(s1[i]=='x' and s2[i]=='y'):
                        xy+=1
                    else:
                        yx+=1
                    #print(i)
            r=0
            r1=0
            r1=yx%2
            yx=yx//2
            r=xy%2
            xy=xy//2
            return (xy)+yx+r+r1
            
        else:
            return -1
__________________________________________________________________________________________________
