__________________________________________________________________________________________________
sample 460 ms submission
class Solution:
    def maxScoreSightseeingPair(self, A: List[int]) -> int:
        current, answer = 0, 0
        for a in A:
            if current + a > answer:
                answer = current + a
            if a > current:
                current = a
            # Take care of j - i
            current -= 1
        return answer
__________________________________________________________________________________________________
sample 16636 kb submission
class Solution:
    def maxScoreSightseeingPair(self, A: List[int]) -> int:
        res = cur = 0
        i = 0
        for j in range(len(A)):
            res = max(res, cur+A[j]+i-j)
            if cur+i -j < A[j]:
                cur = A[j]
                i = j
        return res
__________________________________________________________________________________________________
