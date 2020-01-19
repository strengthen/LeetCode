__________________________________________________________________________________________________
sample 60 ms submission
class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        maximum = -1
        res = [arr[-1]]
        i = len(arr)-1
        
        while i>0:
            if arr[i] > maximum:
                maximum = arr[i]
                
            res.append(maximum)
            i-=1

        res.reverse()
        res[-1] = -1
        return res
__________________________________________________________________________________________________
sample 64 ms submission
class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        if len(arr)==1:
            return [-1]
        mx=-1
        for i in range(len(arr)-1,-1,-1):
            if mx<arr[i]:
                mx , arr[i] = arr[i] , mx
            else:
                arr[i]=mx
        return arr
__________________________________________________________________________________________________
