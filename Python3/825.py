__________________________________________________________________________________________________
sample 276 ms submission
class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        res=0
        nums=[0]*121
        sums=[0]*121
        for i in ages:
            nums[i]+=1
        for i in range(1,121):
            sums[i]=sums[i-1]+nums[i]
        for i in range(15,121):
            if nums[i]==0:
                continue
            count=sums[i]-sums[i//2+7]
            res+=(count-1)*nums[i]
        return res
__________________________________________________________________________________________________
sample 13524 kb submission
class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        count = [0 for i in range(121)]
        for a in ages:
            count[a] += 1
        res = 0
        
        for x in range(121):
            for y in range(121):
                if y <= 0.5*x + 7 or y > x or y > 100 > x:
                    continue
                res += count[x]*count[y]
                if x == y:
                    res -= count[x]
            
        return res
__________________________________________________________________________________________________
