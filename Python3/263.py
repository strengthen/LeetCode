__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def isUgly(self, num: int) -> bool:
        if num<=0:
            return False 
        while(num%30==0 ):
            num=num/30
        while(num%10==0 ):
            num=num/10
        
        while(num%5==0 ):
            num=num/5
        while(num%3==0 ):
            num=num/3    
        while(num%2==0 ):
            num=num/2
        if num==1:
            return True
        else:
            return False
__________________________________________________________________________________________________
sample 13068 kb submission
class Solution:
    def isUgly(self, num: int) -> bool:
        if num <= 0:
            return False
        while num & 1 == 0:
            num >>= 1
        while num % 3 == 0:
            num /= 3
        while num % 5 == 0:
            num /= 5
        return num == 1
__________________________________________________________________________________________________
