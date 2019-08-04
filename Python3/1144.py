__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def movesToMakeZigzag(self, nums: List[int]) -> int:
        min_move = float("inf")
        # A[0] > A[1] < A[2] > A[3] < A[4] > ...
        move = 0
        for i in range(1, len(nums), 2):
            if i + 1 >= len(nums):
                move += max(nums[i] - nums[i - 1] + 1, 0)
            else:
                move += max(nums[i] - nums[i - 1] + 1, nums[i] - nums[i + 1] + 1, 0)
        min_move = min(min_move, move)
        # A[0] < A[1] > A[2] < A[3] > A[4] < ...
        move = max(nums[0] - nums[1] + 1, 0)
        for i in range(2, len(nums), 2):
            if i + 1 >= len(nums):
                move += max(nums[i] - nums[i - 1] + 1, 0)
            else:
                move += max(nums[i] - nums[i - 1] + 1, nums[i] - nums[i + 1] + 1, 0)
        min_move = min(min_move, move)
        return min_move
__________________________________________________________________________________________________
40ms
class Solution:
    def movesToMakeZigzag(self, N: List[int]) -> int:
        m1 = sum(max(0, N[i] - min(N[i-1:i] + N[i+1:i+2]) + 1) for i in range(0, len(N), 2))
        m2 = sum(max(0, N[i] - min(N[i-1:i] + N[i+1:i+2]) + 1) for i in range(1, len(N), 2))
        return min(m1, m2)
__________________________________________________________________________________________________
