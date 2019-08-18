__________________________________________________________________________________________________
sample 104 ms submission
class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        numset = set(nums)
        testbit = 2**30
        if len(numset) <= 1:
            return 0
        def split(numset, testbit):
            set1 = []
            set0 = []
            for num in numset:
                if num & testbit:
                    set1.append(num)
                else:
                    set0.append(num)
            return set1, set0
        def maxXor(set1, set0, testbit):
            maxr = 0
            if len(set1) <= 1 or len(set0) <= 1:
                if len(set1) == 0 or len(set0) == 0:
                    return 0
                if len(set0) == 1:
                    set1, set0 = set0, set1
                op1 = set1[0]
                for n in set0:
                    maxr = max(maxr, op1 ^ n)
                return maxr
            set11, set10 = split(set1, testbit)
            set01, set00 = split(set0, testbit)
            testbit = testbit//2
            maxr = max(maxXor(set11, set00, testbit),
                       maxXor(set10, set01, testbit))
            if maxr > 0:
                return maxr
            return maxXor(set1, set0, testbit)
        while True:
            set1, set0 = split(numset, testbit)
            testbit = testbit//2
            if set1 and set0:
                return maxXor(set1, set0, testbit)
__________________________________________________________________________________________________
sample 108 ms submission
class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        L = len(bin(max(nums)))-2
        ans = 0
        for shift in reversed(range(L)):
            ans <<= 1
            pfx = {i >> shift for i in nums}
            
            for i in pfx:
                if i^1^ans in pfx:
                    ans += 1
                    break
        return ans
__________________________________________________________________________________________________
