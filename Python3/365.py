__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        # gcd 
        if x + y < z: 
            return False 
        if x == z or y == z or x + y == z: 
            return True 
        return z%self.gcd(x, y) == 0 
    
    def gcd(self, a, b): 
        while b != 0: 
            a, b = b, a%b 
        return a
__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        a, b = x, y
        
        while y:
            r = x % y
            x = y
            y = r
            
        return bool(not z or (x and z <= a + b and not z % x))
__________________________________________________________________________________________________
