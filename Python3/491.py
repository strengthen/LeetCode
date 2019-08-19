__________________________________________________________________________________________________
sample 228 ms submission
class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        # use a set to keep track for constant lookup
        subs = {()}
        for num in nums:
            # keep adding new sequences in the set
            subs |= {sub + (num,)
                     for sub in subs
                     if not sub or sub[-1] <= num}
        # return the ones bigger than 1
        return [sub for sub in subs if len(sub) >= 2]
__________________________________________________________________________________________________
sample 21096 kb submission
class Solution:
    def findSubsequences(self, nums: 'List[int]') -> 'List[List[int]]':
        ans = []
        for num in nums:
            cur = []
            for sub in ans:
                if sub[-1] < num:
                    cur.append(sub[:] + [num])
                    cur.append(sub)
                elif sub[-1] == num:
                    cur.append(sub[:] + [num])
                else:
                    cur.append(sub)
            cur.append([num])
            ans = cur
        return  [l for l in ans if len(l) > 1]
__________________________________________________________________________________________________
