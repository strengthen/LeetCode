__________________________________________________________________________________________________
sample 28 ms submission
from itertools import permutations

class Solution:
    def largestTimeFromDigits(self, A: List[int]) -> str:
    	D, T, M = [0]*10, [], 0
    	for t in set(permutations(A)):
    		h = t[0]*10 + t[1]
    		m = 60*h + 10*t[2] + t[3]
    		if h <= 23 and t[2] in [0,1,2,3,4,5] and m < 1440 and m > M: M, T = m, t
    	return f"{T[0]}{T[1]}:{T[2]}{T[3]}" if len(T) !=0 else "00:00" if A == [0,0,0,0] else ""
__________________________________________________________________________________________________
sample 13120 kb submission
class Solution:
     def largestTimeFromDigits(self, A):
        """
        :type A: List[int]
        :rtype: str
        """
        k = sorted(list(itertools.permutations(A)),reverse=True)
        
        for a,b,c,d in k:            
            su = (a*10+b)
            sd = (c*10+d) 

            if su < 24 and sd <60:
                return  f"{a}{b}:{c}{d}"
                
        return ''
__________________________________________________________________________________________________
