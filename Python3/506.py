__________________________________________________________________________________________________
sample 68 ms submission
class Solution:
    def findRelativeRanks(self, nums: List[int]) -> List[str]:
        A = nums
        T = sorted(range(len(nums)), key = lambda i: A[i], reverse=True)
        x = ["Gold Medal", "Silver Medal", "Bronze Medal"]
        for idx, i in enumerate(T):
            if idx <= 2: A[i] = x[idx]
            else: A[i] = str(idx + 1)
        return A
__________________________________________________________________________________________________
sample 14116 kb submission
#
# @lc app=leetcode id=506 lang=python3
#
# [506] Relative Ranks
#
class Solution:
    def findRelativeRanks(self, nums: List[int]) -> List[str]:
        n = nums[:]
        n.sort(reverse=True)
        d= {}
        d[n[0]] = "Gold Medal"
        if len(n) >= 2:
            d[n[1]] = "Silver Medal"
        if len(n) >= 3:
            d[n[2]] = "Bronze Medal"

        i = 4
        for x in n[3:]:
            d[x] = str(i)
            i+=1
        a=[]
        for i in nums:
            a.append(d[i])
        return a
__________________________________________________________________________________________________
