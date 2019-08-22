__________________________________________________________________________________________________
sample 616 ms submission
class Solution:
    def longestOnes(self, A: List[int], K: int) -> int:
        i = 0
        for j in range(len(A)):
            if not A[j]:
                K -= 1
            if K < 0:
                if not A[i]:
                    K += 1
                i += 1

        return j - i + 1
__________________________________________________________________________________________________
sample 13264 kb submission
class Solution:
    def longestOnes(self, A: List[int], K: int) -> int:
        i = 0
        for j in range(len(A)):
            K -= 1 - A[j]
            if K < 0:
                K += 1 - A[i]
                i += 1
        return j - i + 1
__________________________________________________________________________________________________
