__________________________________________________________________________________________________
sample 60 ms submission
class Solution:      
        
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left, right = 0, len(numbers)-1
        sum = numbers[left]+ numbers[right]
        while sum != target:
            if sum <target:
                left += 1
            if sum > target:
                right -=1 
            sum  = numbers[left]+ numbers[right]
        return [left+1,right+1]
__________________________________________________________________________________________________
sample 13436 kb submission
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        d={}
        for i in range(len(numbers)):
            if target<numbers[i] and target>0:
                break
            c=target -numbers[i]
            if(c in d):
                return d[c]+1,i+1
            d[numbers[i]]=i
__________________________________________________________________________________________________
