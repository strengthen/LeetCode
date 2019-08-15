__________________________________________________________________________________________________
sample 76 ms submission
class NumArray:

    def __init__(self, nums: List[int]):
        self.nums=nums
        l=[]
        s1=0
        for i in range(len(nums)):
            s1 += nums[i]
            l.append(s1)
        self.list=l
        

    def sumRange(self, i: int, j: int) -> int:
        if i==0:
            return self.list[j]
        else:
            return self.list[j]-self.list[i-1]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)
__________________________________________________________________________________________________
sample 16444 kb submission
class NumArray:

    def __init__(self, nums: List[int]):
        self.n = nums

    def sumRange(self, i: int, j: int) -> int:
        return sum(self.n[i:j+1])


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)
__________________________________________________________________________________________________
