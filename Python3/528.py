__________________________________________________________________________________________________
sample 188 ms submission
from random import random
class Solution:

    def __init__(self, w: List[int]):
        self.check, cur, total = [], 0, sum(w)
        for x in w:
            cur += x
            self.check.append(cur / total)
        
    def pickIndex(self) -> int:
        return bisect.bisect(self.check, random())
__________________________________________________________________________________________________
sample 16804 kb submission
class Solution:

    def __init__(self, w: List[int]):
        for i in range(1,len(w)):
            w[i]+=w[i-1]
        self.w=w
    def pickIndex(self) -> int:
        # return self.w
        key=random.randint(1,self.w[-1])
        left,right=0,len(self.w)-1
        while left<=right:
            if left==right:
                return left
            if self.w[left]==key:
                return left
            if self.w[right]==key:
                return right
            mid=(left+right)//2
            if key == self.w[mid]:
                return mid
            if key<self.w[mid]:
                if key>self.w[mid-1]:
                    return mid
                else:
                    right=max(mid-1,0)
            if key > self.w[mid]:
                if key < self.w[mid+1]:
                    return mid+1
                else:
                    left=min(mid+1,len(self.w)-1)

# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()
__________________________________________________________________________________________________
