__________________________________________________________________________________________________
sample 40 ms submission
class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        aset = collections.Counter(answers)
        return sum((c // (n + 1) + (c % (n + 1) != 0)) * (n + 1) for n, c in aset.items())
__________________________________________________________________________________________________
sample 13180 kb submission
class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        samecolor_num={}
        res=0
        for n in answers:
            if n not in samecolor_num:
                res+=(1+n)
                samecolor_num[n]=n
            else:
                samecolor_num[n]-=1
            if samecolor_num[n]==0:
                del samecolor_num[n]
                
        return res       
__________________________________________________________________________________________________
