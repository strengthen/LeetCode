__________________________________________________________________________________________________
sample 0 ms submission
class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        for i in range(0,16):
            j = 31-i
            if (n>>i) & 1 != (n>>j) & 1:
                n = n ^ (1<<i | 1<<j)
        return n
__________________________________________________________________________________________________
sample 11556 kb submission
class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        return int("{:032b}".format(n)[::-1], 2)
__________________________________________________________________________________________________
