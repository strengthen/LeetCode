__________________________________________________________________________________________________
sample 40 ms submission
class Solution:
    def lastRemaining(self, n: int) -> int:
        curr = 1
        diff = 1
        i = 1
        while n > 1:
            if i % 2 or n % 2:
                curr += diff
            diff <<= 1
            i += 1
            n >>= 1
        return curr    
__________________________________________________________________________________________________
sample 13160 kb submission
class Solution:  
    # from discussion (iterative)
    def lastRemaining(self, n: int) -> int: 
        step = 1
        head = 1
        left = True
        
        while n > 1:
            if left or n % 2:
                head += step
            
            n //= 2
            step *= 2
            left = not left
        
        return head
__________________________________________________________________________________________________
