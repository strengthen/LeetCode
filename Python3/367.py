__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        i,j=1,num
        while i<=j:
            mid=i+(j-i)//2
            if mid*mid==num:
                return True
            if mid*mid<num:
                i=mid+1
            else: #mid>num
                j=mid-1
        return False
__________________________________________________________________________________________________
sample 12932 kb submission
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        miniI = 1
        maxiI = num-1
        middle = (maxiI+miniI)//2
        while maxiI-miniI > 1:
            middle = (maxiI+miniI)//2
            if middle**2 == num:
                break
            elif middle**2 > num:
                maxiI = middle
            else:
                miniI = middle
        
        if middle**2==num:
            return True
        elif miniI**2 == num:
            return True
        elif maxiI**2 == num:
            return True
        else:
            return False
__________________________________________________________________________________________________
