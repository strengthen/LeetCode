__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def strWithout3a3b(self, A: int, B: int) -> str:
        res=[]
        
        high,low = max(A,B),min(A,B)
        letter_high = 'a' if A==high else 'b'
        letter_low = 'b' if letter_high=='a' else 'a'
        while high>low and high>0 and low>0 and high>=2:
            res.append(letter_high)
            res.append(letter_high)
            res.append(letter_low)
            high-=2
            low-=1
        while high>0 and low>0:
            res.append(letter_high)
            res.append(letter_low)
            high-=1
            low-=1
        while high>0:
            res.append(letter_high)
            high-=1
        while low>0:
            res.append(letter_low)
            low-=1
        return ''.join(res)
__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def strWithout3a3b(self, A: int, B: int) -> str:
        #A,B = 5,2
        low = min(A,B)
        middle ='ab'*low
        
        if A==B:
            return middle
        elif A>B:
            middle = middle + 'a' 
            for i in range(A-low-1):
                middle = middle[:3*i] + 'a' + middle[3*i:]
        else:
            middle = 'b' + middle
            for i in range(B-low-1):
                middle = middle[:3*i] + 'b' + middle[3*i:]
        #print(middle)
        return middle     
__________________________________________________________________________________________________
