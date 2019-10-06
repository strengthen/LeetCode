__________________________________________________________________________________________________
96ms
class Solution:
def arraysIntersection(self, arr1: List[int], arr2: List[int], arr3: List[int]) -> List[int]:
    l = [0 for i in range(max(arr1[-1],arr2[-1],arr3[-1]))]
    answer = []
    
    for x in arr1:
        l[x-1] = l[x-1]+1
    
    for x in arr2:
        l[x-1] = l[x-1]+1
        
    for x in arr3:
        if l[x-1] == 2:
            answer.append(x)
            
    return answer
__________________________________________________________________________________________________

__________________________________________________________________________________________________
