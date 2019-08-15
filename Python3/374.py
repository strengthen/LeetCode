__________________________________________________________________________________________________
sample 0 ms submission
# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num):

class Solution(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        left = 1
        right = n
        
        while left <= right:
            mid = (left + right) / 2
            ret = guess(mid)
            
            if ret == 0: 
                return mid
            elif ret == -1:
                right = mid - 1
            else:
                left = mid + 1
__________________________________________________________________________________________________
sample 11608 kb submission
# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num):

class Solution(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        low=1
        high=n
        while low<=high:
            mid=(low+high)//2
            if guess(mid)==0:
                return mid
            elif guess(mid)==-1:
                high=mid-1
            else:
                low=mid+1
__________________________________________________________________________________________________
