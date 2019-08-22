__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def reverseOnlyLetters(self, S: str) -> str:
        ans = []
        stack = [i for i in S if i.isalpha()]
        for i in S:
            if i.isalpha():
                ans.append(stack.pop())
            else:
                ans.append(i)
        return "".join(ans)        
__________________________________________________________________________________________________
sample 12924 kb submission
class Solution:
    def reverseOnlyLetters(self, S: str) -> str:
        p1=0
        p2=len(S)-1
        newS=list(S)
        while p1<p2:

            while not newS[p1].isalpha() and p1<p2:
                p1+=1
            while not newS[p2].isalpha() and p2>p1:
                p2-=1
            tmp=newS[p1]
            newS[p1]=newS[p2]
            newS[p2]=tmp
            p1+=1
            p2-=1
        return ''.join(newS)
__________________________________________________________________________________________________
