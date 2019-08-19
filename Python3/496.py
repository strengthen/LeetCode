__________________________________________________________________________________________________
sample 44 ms submission
class Solution:    
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        stk=[]
        d=dict()
        for num in nums2:
            while len(stk)>0 and num>stk[-1]:
                top = stk[-1]
                d[top] = num
                stk.pop()
            stk.append(num)
        ans=[]
        for num in nums1:
            if num not in d: ans.append(-1)
            else: ans.append(d[num])
        return ans
__________________________________________________________________________________________________
sample 12976 kb submission
#
# @lc app=leetcode id=496 lang=python3
#
# [496] Next Greater Element I
#


class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:

        result = []
        for n in nums1:
            find_greater = False
            ind = nums2.index(n)
            for right_n in nums2[ind+1:]:
                if right_n > n:
                    result.append(right_n)
                    find_greater = True
                    break
            if not find_greater:
                result.append(-1)

        return result
__________________________________________________________________________________________________
