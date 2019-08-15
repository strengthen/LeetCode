__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def addDigits(self, num: int) -> int:
        if num == 0 : return 0
        else:return (num - 1) % 9 + 1
        
        '''
        num = str(num)
        
        while len(num) > 1:
            num_sum = 0
            for char in num:
                num_sum += int(char)
            num = str(num_sum)
        
        return int(num)
        '''
        
        # [1,9]
        
        # 54 = 9
        
        # 66 = 12 = 3
        # 3
        
    
        # '3232' = 1
        # '38' = 
        # '1', '2', '3' = 6
__________________________________________________________________________________________________
sample 13048 kb submission
class Solution:
    def addDigits(self, num: int) -> int:
        
        def add(n):
            if n < 10:
                return n
            else:
                s = sum([int(x) for x in str(n)])
                return add(s)
                
        return add(num)
__________________________________________________________________________________________________
