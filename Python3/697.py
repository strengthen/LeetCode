__________________________________________________________________________________________________
sample 236 ms submission
from collections import Counter
class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        c = Counter(nums)
        degree, front, end, minlen, curr = 0, 0, 0, 50001, 0
        candi = []
        
        if c.most_common()[0][1] == 1:
            return 1
        
        for i in c.most_common():
            if i[1] >= degree:
                degree = i[1]
                candi.append(i[0])
            else:
                break
                
        while candi:
            curr = candi.pop()
            front = nums.index(curr)
            for i in range(len(nums)-1, -1, -1):
                if nums[i] == curr:
                    end = i
                    break
            if end - front + 1 < minlen:
                minlen = end - front +1
                
        return minlen
__________________________________________________________________________________________________
sample 13816 kb submission
class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        first, cnt, degree, ans = {}, {}, 0, 0
        for index, num in enumerate(nums):
            first.setdefault(num, index)
            cnt[num] = cnt.get(num, 0) + 1
            if degree < cnt[num]:
                degree = cnt[num]
                ans = index - first[num] + 1
            elif degree == cnt[num]:
                ans = min(ans, index - first[num] + 1)
        return ans        
__________________________________________________________________________________________________
