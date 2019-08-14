__________________________________________________________________________________________________
sample 0 ms submission
class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        mybin = bin(n)
        return mybin.count('1')
__________________________________________________________________________________________________
sample 11608 kb submission
class Solution(object):
    def hammingWeight(self, n):
        return bin(n).count('1')
__________________________________________________________________________________________________
