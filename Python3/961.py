__________________________________________________________________________________________________
sample 216 ms submission
class Solution:
    def repeatedNTimes(self, A: List[int]) -> int:
        d = {}
        for num in A:
            if num in d.keys():
                return num
            else:
                d[num] = 1        
__________________________________________________________________________________________________
sample 13836 kb submission
class Solution:
    def repeatedNTimes(self, A: List[int]) -> int:
        bucket = [0] * (max(A)+1)
        for eachEle in A:
            bucket[eachEle] += 1
        return bucket.index(len(A)//2)
__________________________________________________________________________________________________
