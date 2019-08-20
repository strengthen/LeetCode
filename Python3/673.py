__________________________________________________________________________________________________
sample 84 ms submission
from bisect import bisect_left
class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        min_end = [float('inf') for _ in nums]
        count = [0 for _ in nums]
        candi = [[] for _ in nums]
        for n in nums:
            i = bisect_left(min_end, n)
            min_end[i] = n
            if i > 0:
                while candi[i - 1][0][0] >= n:
                    count[i - 1] -= candi[i - 1].pop(0)[1]
                count_e = count[i - 1]
            else:
                count_e = 1
            count[i] += count_e
            candi[i].append((n, count_e))
        # print(count)
        for i in range(len(nums) - 1, -1, -1):
            if count[i] > 0:
                return count[i]
        return 0
__________________________________________________________________________________________________
sample 13116 kb submission
class Solution:
    def findNumberOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if nums == []:
            return 0
        LIS, cnt = [1]*len(nums), [1]*len(nums)
        for i in range(1, len(nums)):
            for j in range(0,i):
                if nums[i] > nums[j]:
                    if LIS[i] == LIS[j]+1:
                        cnt[i] += cnt[j]
                    elif LIS[i] < LIS[j]+1:
                        cnt[i] = cnt[j]
                        LIS[i] = LIS[j]+1
        return sum((y for x,y in zip(LIS, cnt) if x==max(LIS)))
__________________________________________________________________________________________________
