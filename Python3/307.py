__________________________________________________________________________________________________
sample 112 ms submission
class NumArray:
    def __init__(self, nums: List[int]):
        if not nums:
            return 
        
        n = len(nums)
        self.nums = nums
        self.k = math.ceil(n ** 0.5)  # bucket size
        self.n = math.ceil(n / self.k)  # bucket count
        self.buckets = [0] * self.n
        
        for i, x in enumerate(nums):
            self.buckets[i // self.k] += x

    def update(self, i: int, val: int) -> None:
        self.buckets[i // self.k] += val - self.nums[i]
        self.nums[i] = val

    def sumRange(self, i: int, j: int) -> int:
        start = i // self.k
        x = start * self.k
        end = j // self.k
        y = end * self.k
        
        lsum = self.buckets[start] - sum(self.nums[x:i])
        rsum = sum(self.nums[y:j + 1])
        
        total = lsum + rsum + sum(self.buckets[start + 1:end])
        
        if start == end:
            return total - self.buckets[start]
        
        return total
__________________________________________________________________________________________________
sample 16556 kb submission
class NumArray:

    def __init__(self, nums: List[int]):
    
        self.array = nums
        

    def update(self, i: int, val: int) -> None:
    
        self.array[i] = val
        

    def sumRange(self, i: int, j: int) -> int:
    
        return sum(self.array[i : j + 1])
__________________________________________________________________________________________________
