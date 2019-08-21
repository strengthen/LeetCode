__________________________________________________________________________________________________
sample 144 ms submission
class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        
        num5 = 0
        num10 = 0
        num20 = 0
        if not bills[0]==5:
            return False
        for b in bills:
            if b==5:
                num5+=1
            elif b==10:
                if num5==0:
                    return False
                num5-=1
                num10+=1
            elif b==20:
                if num5>=1 and num10>=1:
                    num5-=1
                    num10-=1
                    num20+=1
                elif num5>=3 and num10==0:
                    num5-=3
                    num20+=1
                else:
                    return False
        return True
__________________________________________________________________________________________________
sample 13264 kb submission
class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        drawer = { 5: 0, 10: 0}
        for bill in bills:
            if bill != 20: drawer[bill] += 1
            bill -= 5
            while drawer[10] > 0 and bill >= 10:
                bill -= 10
                drawer[10] -= 1
            while drawer[5] > 0 and bill >= 5:
                bill -= 5
                drawer[5] -= 1
            if bill != 0: return False
        return True
__________________________________________________________________________________________________
