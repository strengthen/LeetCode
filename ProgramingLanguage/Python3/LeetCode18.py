__________________________________________________________________________________________________
60ms
from bisect import bisect_left, bisect_right
import collections
class Solution:
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        if len(nums) < 4:
            return []
        res = []
        count = collections.Counter(nums)
        keys = list(count.keys())
        keys.sort()
        hi = keys[-1]
        fo = target//4
        if fo in count and fo*4==target:
            if count[fo]>=4:
                res.append([fo,fo,fo,fo])
        a_min = bisect_left(keys,target-3*hi)
        a_max = bisect_right(keys,target//4+1)
        for ai in range(a_min, a_max):
            a = keys[ai]
            dp = target-3*a
            if count[a]>=3 and dp in count and dp>a:
                res.append([a,a,a,dp])
            cd = target-2*a
            if count[a]>=2:
                for ci in range(max(ai+1,bisect_left(keys, cd-hi)), bisect_right(keys, cd//2+1)):
                    c = keys[ci]
                    d = target-a*2-c
                    if c<=d and d in count:
                        if c<d or count[c]>=2:
                            res.append([a,a,c,d])
            b_min = max(ai+1, bisect_left(keys, target-a-2*hi))
            b_max = bisect_right(keys, (target-a)//3+1)
            for bi in range(b_min, b_max):
                b = keys[bi]
                if count[b]>=3:
                    if a+3*b==target:
                        res.append([a,b,b,b])
                if count[b]>=2:
                    d = target-a-b*2
                    if b<d and d in count:
                        res.append([a,b,b,d])
                c_min = max(bi+1, bisect_left(keys, target-a-b-hi))
                c_max = bisect_right(keys, (target-a-b)//2+1)
                for ci in range(c_min, c_max):
                    c = keys[ci]
                    d = target-a-b-c
                    if c<=d and d in count:
                        if c<d or count[c]>=2:
                            res.append([a,b,c,d])
        return res
__________________________________________________________________________________________________
64ms
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        n = len(nums)
        if n < 4:
            return []
        res = []
        nums = sorted(nums)
        hi = nums[-1]
        num2id = {x:i for i,x in enumerate(nums)}
        for i in range(n-3):
            if i > 0 and nums[i]==nums[i-1]:
                continue
            a = nums[i]
            if a*4 >target:
                return res
            if  a+3*hi<target:
                continue
            for j in range(i+1,n-2):
                if j > i+1 and nums[j]==nums[j-1]:
                    continue
                b = nums[j]
                if a+b*3 >target:
                    break
                if a+b+2*hi<target:
                    continue
                for k in range(j+1,n-1):
                    if k > j+1 and nums[k]==nums[k-1]:
                        continue
                    c = nums[k]
                    if a+b+c*2>target:
                        break
                    if a+b+c+hi<target:
                        continue
                    d = target-a-b-c
                    if d in num2id:
                        l = num2id[d]
                        if l <= k:
                            break
                        else:
                            res.append([a,b,c,d])
        return res                    
__________________________________________________________________________________________________
72ms
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        
        # special case
        n = len(nums)
        if n < 4:
            return([])
        
        # sort your number first
        nums.sort()
        
        h_t = {}
        for i, num in enumerate(nums):
           h_t[num] = i
        
        res = []        
        
        
        for i in range(n-3):
            if i != 0 and nums[i] == nums[i-1]:
                continue            
            elif nums[i] + 3* nums[n-1] < target:
                continue
            elif 4 * nums[i] > target:
                break
            for j in range(i+1, n-2):
                if j != i+1 and nums[j] == nums[j-1]:
                    continue
                elif nums[i] + nums[j] + 2*nums[n-1] < target:
                    continue
                elif nums[i] + nums[j]*3 > target:
                    break
                for k in range(j+1, n-1):
                    if k != j+1 and nums[k] == nums[k-1]:
                        continue
                    elif nums[i] + nums[j] + nums[k]  + nums[n-1] < target:
                        continue
                    elif nums[i] + nums[j] + 2*nums[k] > target:
                        break
                    
                    diff = target - nums[i] - nums[j] - nums[k]
                    if diff in h_t and h_t[diff] > k:
                        temp = [nums[i], nums[j], nums[k], diff]
                        res.append(temp)
        return(res)
__________________________________________________________________________________________________
12220 kb
class Solution:
    def fourSum(self, nums: 'List[int]', target: 'int') -> 'List[List[int]]':
        if len(nums) < 4:
            return []
        
        nums = sorted(nums)
        
        solution_sets = []
        
        for p1 in range(len(nums) - 3):
            if nums[p1] * 4 > target or nums[-1] * 4 < target:
                continue
                
            if p1 > 0 and nums[p1] == nums[p1-1]:
                continue
                
            for p2 in range(p1 + 1, len(nums) - 2):
                if p2 > p1 + 1 and nums[p2] == nums[p2-1]:
                    continue
                
                l = p2 + 1
                r = len(nums) - 1
                while l < r:
                    curr_sum = nums[p1] + nums[p2] + nums[l] + nums[r]
                    
                    if curr_sum > target:
                        while l < r and curr_sum > target:
                            r -= 1
                            curr_sum = nums[p1] + nums[p2] + nums[l] + nums[r]
                    elif curr_sum < target:
                        while l < r and curr_sum < target:
                            l += 1
                            curr_sum = nums[p1] + nums[p2] + nums[l] + nums[r]
                    else:
                        solution_set = (nums[p1], nums[p2], nums[l], nums[r])
                        solution_sets.append(solution_set)
                        l += 1
                        while l < r and nums[l-1] == nums[l]:
                            l += 1
                        r -= 1
                        while l < r and nums[r+1] == nums[r]:
                            r -= 1
                            
        return solution_sets
__________________________________________________________________________________________________
12228 kb
class Solution(object):
 def fourSum(self,q,t):
  k=[]
  q.sort()
  for i in range(len(q)-3):
   #if abs(q[i])<=abs(t):
   for j in range(i+1,len(q)-2,1):
  #   if abs(q[i]+q[j])<=abs(t):
    low=j+1
    l1=j+1
    high=len(q)-1
    h1=len(q)-1
    while low<high:
     if q[i]+q[j]+q[low]+q[high]==t:
      if [q[i],q[j],q[low],q[high]] not in k:
       k.append([q[i],q[j],q[low],q[high]])
      #  while q[l1]!=q[low] and l1<len(q)-1:
      #   l1=l1+1
      ##  if low==l1:
      #   low=low+1
      #  else:
      #   low=l1 
      low=low+1 
     elif q[i]+q[j]+q[low]+q[high]<t:
       # while q[l1]!=q[low] and l1<len(q)-1:
       #  l1=l1+1
       # if low==l1:
       #  low=low+1
       # else:
       #  low=l1 
      low=low+1
     else:
        #while q[h1]!=q[high] and h1<j+1:
        # h1=h1-1
        #if high==h1:
        # high=high-1
       # else:
        # high=h1 
      high=high-1
  return k   

__________________________________________________________________________________________________
