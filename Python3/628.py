__________________________________________________________________________________________________
sample 276 ms submission
class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        min1, min2 = float('inf'), float('inf')
        max1, max2, max3 = -float('inf'), -float('inf'), -float('inf')
        
        for num in nums:
            if num < min1:
                min1 = num
                if min1 < min2:
                    min1, min2 = min2, min1
            
            if num > max1:
                max1 = num
                if max1 > max2:
                    max2, max1 = max1, max2
                if max2 > max3:
                    max3, max2 = max2, max3
        
        return max(min1*min2*max3, max1*max2*max3)
__________________________________________________________________________________________________
sample 13948 kb submission
class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        a = sorted(nums)
        aa = a[0] * a[1] 
        bb = a[-2] * a[-3]
        if a[-1] > 0: return a[-1] * bb if bb > aa else a[-1] * aa
        else: return a[-1] * bb
__________________________________________________________________________________________________
