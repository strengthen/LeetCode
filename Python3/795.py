__________________________________________________________________________________________________
sample 372 ms submission
# look at every usb array individually and compare elements to L and R -> O(n^3)

# use stack
# iterate through A
# keep track of max of the current stack
# if max <

# if you find an element that is between L and R, then all subarrays consisting of that element and elements to the left and rihgt of it
# which are less than R will be valid subarrays


class Solution:
    def numSubarrayBoundedMax(self, A: List[int], L: int, R: int) -> int:
        res, dp = 0, 0
        prev = -1
        for i,a in enumerate(A):
            if a < L:
                res += dp
            elif a > R:
                dp = 0
                prev = i
            else:
                dp = i - prev
                res += dp
        return res
__________________________________________________________________________________________________
sample 14136 kb submission
class Solution:
    def numSubarrayBoundedMax(self, A: List[int], L: int, R: int) -> int:
        prev = -1
        res = 0
        last = 0
        for i, n in enumerate(A):
            if L<=n<=R:
                last = i-prev
                res += last
            elif n<=L:
                res += last
            else:
                prev = i
                last = 0
        return res                
__________________________________________________________________________________________________
