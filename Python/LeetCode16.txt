__________________________________________________________________________________________________
36ms
class Solution1:
    def threeSumClosest(self, nums: 'List[int]', target: 'int') -> 'int':
        if len(nums) < 3:
            return 0
        if len(nums) == 3:
            return nums[0] + nums[1] + nums[2]
        nums.sort()
        closest = target
        import sys
        b = sys.maxsize
        # a = []
        for i in range(len(nums)):
            l = i + 1
            r = len(nums) - 1
            while l < r:
                tmp = nums[i] + nums[l] + nums[r]
                tmp_b = target - tmp
                if tmp_b == 0:
                    return target
                if abs(tmp_b) < b:
                    closest = tmp
                    b = abs(tmp_b)
                    # a.append((nums[i], nums[l], nums[r]))
                if tmp_b > 0:
                    l += 1
                if tmp_b < 0:
                    r -= 1
        # print(a)
        return closest
    
class Solution2:
    def threeSumClosest(self, nums: 'List[int]', target: 'int') -> 'int':
        nums.sort()
        result = nums[0]+nums[1]+nums[2]
        clost = []
        for i in range(0, nums.__len__()-2):
            j, k = i+1, nums.__len__()-1
            if nums[i]+nums[k-1]+nums[k] < target:
                clost.append(nums[i]+nums[k-1]+nums[k])
            elif nums[i]+nums[j]+nums[j+1] > target:
                clost.append(nums[i]+nums[j]+nums[j+1])
            else:
                while j<k:
                    temp = nums[i]+nums[j]+nums[k]
                    if temp == target:
                        return temp
                    clost.append(temp)
                    if temp < target:
                        j += 1
                    else:
                        k -= 1
        clost = sorted(clost, key=lambda x:abs(target-x))
        return clost[0]

class Solution:
    def threeSumClosest(self, nums: 'List[int]', target: 'int') -> 'int':
        def min(curr, closest, last_b):
            tmp_b = target - curr
            if abs(tmp_b) < abs(last_b):
                return curr, tmp_b
            return closest, last_b

        nums.sort()
        closest = target
        import sys
        b = sys.maxsize
        for i in range(0, nums.__len__() - 2):
            j, k = i + 1, nums.__len__() - 1
            if nums[i] + nums[k - 1] + nums[k] < target:
                closest, b = min(nums[i] + nums[k - 1] + nums[k], closest, b)
            elif nums[i] + nums[j] + nums[j + 1] > target:
                closest, b = min(nums[i] + nums[j] + nums[j + 1], closest, b)
            else:
                while j < k:
                    temp = nums[i] + nums[j] + nums[k]
                    if temp == target:
                        return temp
                    closest, b = min(temp, closest, b)
                    if temp < target:
                        j += 1
                    else:
                        k -= 1
        return closest
__________________________________________________________________________________________________
40ms
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        ans = 0
        closest = sys.maxsize
        n = sorted(nums)
        size = len(nums)
        for i in range(size-2):
            if i > 0 and n[i] == n[i-1]:
                continue
            a = n[i]
            hi = size - 1
            lo = i + 1
            maxValue = a + n[hi-1] + n[hi]
            if maxValue < target:
                if target - maxValue < closest:
                    closest = target - maxValue
                    ans = maxValue
                continue
            minValue = a + n[lo] + n[lo+1]
            if minValue > target:
                if minValue - target < closest:
                    closest = minValue-target
                    ans = minValue
                continue
            
            while lo < hi:                
                if lo > i + 1 and n[lo] == n[lo-1]:
                    lo += 1
                    continue
                if hi < size - 1 and n[hi] == n[hi+1]:
                    hi -= 1
                    continue
                b = n[hi]
                c = n[lo]
                val = abs(a + b + c - target)
                if val == 0:
                    return target
                s = a + b + c
                if val < closest:
                    closest = val
                    ans = s
                
                if s < target:
                    lo += 1
                else:
                    hi -= 1
        
        return ans                
__________________________________________________________________________________________________
48ms
class Solution:
    def threeSumClosest(self, ns: List[int], tar: int) -> int:
        ns.sort()
        if len(ns)<3:
            return 0
        res = ns[0]+ns[1]+ns[2]
        for i in range(len(ns)-2):
            l, r = i+1, len(ns)-1
            if i>0 and ns[i]==ns[i-1]:     #skip duplicate to speed up
                continue
            s0, s2=ns[i]+ns[l]+ns[l+1],ns[i]+ns[r]+ns[r-1]
            if s0>tar and abs(res-tar)>s0-tar:     #check extreme case first and speed up
                res = s0
            elif s2<tar and abs(res-tar)>tar-s2:
                res=s2
            else:
                while l<r:
                    s1=ns[i]+ns[l]+ns[r]
                    if s1==tar:
                        return tar
                    if abs(res-tar)>abs(s1-tar):
                        res=s1
                    if s1-tar<0:
                        l+=1
                    else:
                        r-=1
        return res
__________________________________________________________________________________________________
12120 kb
class Solution:
    def threeSumClosest(self, nums: 'List[int]', target: 'int') -> 'int':
        nums.sort()
        diff = sys.maxsize
        ans = 0
        n = len(nums)
        for i in range(n):
            l, r = i+1, n-1
            while l < r:
                sum = nums[i] + nums[l] + nums[r]
                if abs(target-sum)<diff:
                    ans = sum
                    diff = abs(target-sum)
                if sum > target:
                    r -= 1
                else:
                    l += 1
        return ans
__________________________________________________________________________________________________
12128 kb
class Solution:
    def threeSumClosest(self, nums: 'List[int]', target: 'int') -> 'int':

        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()

        three_sum_closest = float('inf')
        three_sum_closest_distance = abs(target - three_sum_closest)
        for i in range(len(nums) - 2):
            l, r = i + 1, len(nums) - 1
            two_sum_target = target - nums[i]
            while l < r:

                triplet_sum = nums[i] + nums[l] + nums[r]
                triplet_sum_distance = abs(target - triplet_sum)
                if three_sum_closest_distance > triplet_sum_distance:
                    three_sum_closest = triplet_sum
                    three_sum_closest_distance = triplet_sum_distance

                two_sum = nums[l] + nums[r]
                if two_sum > two_sum_target:
                    r -= 1
                elif two_sum < two_sum_target:
                    l += 1
                else:
                    return three_sum_closest

        return three_sum_closest
__________________________________________________________________________________________________
