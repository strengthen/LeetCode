__________________________________________________________________________________________________
sample 328 ms submission
class Solution:
    def findLHS(self, nums: List[int]) -> int:
        di, count = collections.Counter(nums), 0
        for key in di:
            if key + 1 in di:
                count = max(count, di[key] + di[key + 1])
        return count
__________________________________________________________________________________________________
sample 14304 kb submission
class Solution:
    def findLHS(self, nums: List[int]) -> int:
        # length of subsequence is basically longest set that has only val and val+/-1
        # this then becomes count
        # and value can have only 2
        cnt = collections.Counter()
        res = 0
        for i in nums:
            cnt[i]+=1
            if cnt[i+1]>0 or cnt[i-1]>0: res = max(res, cnt[i]+cnt[i-1], cnt[i]+cnt[i+1])
        return res
__________________________________________________________________________________________________
