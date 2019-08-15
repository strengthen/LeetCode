__________________________________________________________________________________________________
sample 20 ms submission
# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution:
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        low=1
        high=n
        
        while low<high:
            mid=(low+high)//2
            if isBadVersion(mid):
                high=mid
            else:
                low=mid+1
        return low
__________________________________________________________________________________________________
sample 12960 kb submission
# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution:
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        left = 1
        right = n
        while left < right:
          mid = left + (right - left) // 2
          if isBadVersion(mid):
            right = mid
          else:
            left = mid + 1
        return left
__________________________________________________________________________________________________
