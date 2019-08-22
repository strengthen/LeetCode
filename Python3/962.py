__________________________________________________________________________________________________
sample 320 ms submission
class Solution:
    def maxWidthRamp(self, A: List[int]) -> int:
        s = []
        res = 0
        for i in range(len(A)):
            if not s or A[s[-1]] > A[i]:
                s.append(i)
        for i in range(len(A)-1, -1, -1):
            while s and A[s[-1]] <= A[i]:
                res = max(res, i - s.pop())
        return res
__________________________________________________________________________________________________
sample 324 ms submission
class Solution:
    def maxWidthRamp(self, A: List[int]) -> int:
        st = []
        for i in range(len(A)):
            if (not st) or A[i] < A[st[-1]]:
                st.append(i)
        res = 0
        for i in range(len(A))[::-1]:
            while st and A[st[-1]] <= A[i]:
                res = max(res, i - st.pop())
        return res
__________________________________________________________________________________________________
