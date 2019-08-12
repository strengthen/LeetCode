__________________________________________________________________________________________________
sample 16 ms submission
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        if digits[-1] != 9:
            digits[-1] += 1
        else:
            found = False
            for i in range(len(digits)-1,-1,-1):
                if digits[i] == 9:
                    digits[i] = 0
                else:
                    digits[i] += 1
                    found = True
                    break
            if not found:
                digits = [1] + digits
        
        return digits
__________________________________________________________________________________________________
sample 12908 kb submission
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        
        s = ""
        
        for d in digits:
            s += str(d)
        
        num = int(str(s)) + 1 
        
        return [int(d) for d in str(num)]            
__________________________________________________________________________________________________
