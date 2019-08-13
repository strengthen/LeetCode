__________________________________________________________________________________________________
sample 84 ms submission
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return sum(set(nums))*2 - sum(nums)
__________________________________________________________________________________________________
sample 14412 kb submission
def singleNumber(A):
    x = 0
    for i in A:
        x ^= i
    return x

class Solution:
    def singleNumber(self, A):
        return singleNumber(A)
__________________________________________________________________________________________________
sample 14468 kb submission
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        nums=sorted(nums)
        unique=None
        ignore=None
        last=None
        count=0
        for num in nums:
            if num != last:
                if count == 1:
                    return last
                last=num
                count=1
            else:
                count+=1
        return last
                
             
    def singleNumber_with_hash(self, nums: List[int]) -> int:
        tracker={}
        for num in nums:
            if num in tracker:
                tracker[num]+=1
            else:
                tracker[num]=1
        for key,item in tracker.items():
            if item == 1:
                return key       