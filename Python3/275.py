__________________________________________________________________________________________________
sample 148 ms submission
class Solution:
    def hIndex(self, citations: List[int]) -> int:      
        max_cita = len(citations)
        left, right = 0, max_cita - 1
        
        while left <= right:
            mid = (left + right) // 2
            
            if citations[mid] == max_cita - mid:
                return max_cita - mid
            elif citations[mid] < max_cita - mid:
                left = mid + 1
            else:
                right = mid - 1
                
        return max_cita - (right+1)
__________________________________________________________________________________________________
sample 16648 kb submission
class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        
        length = len(citations)
        
        first = 0
        count = length
        
        while count > 0:
            step = int(count / 2)
            mid = first + step
            if citations[mid] < length - mid:
                first = mid + 1
                count -= (step + 1)
            else:
                count = step
        
        return length - first
__________________________________________________________________________________________________
