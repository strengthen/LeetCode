__________________________________________________________________________________________________
244ms
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if not nums: return []
        # nn = []
        count = {}
        for n in nums:
            if n not in count:
                count[n] = 0
            count[n] += 1
            # if count[n] < 4:
            #     nn.append(n)
        # nums = nn
        # d = collections.defaultdict(set)
        # for i,n in enumerate(nums):
            # d[n].add(i)
        ans = []
        nums = sorted(count)
        # nums = nums[bisect.bisect_left(nums, -2*nums[-1]):]
        for i,n in enumerate(nums):
            if count[n] >= 2:
                if n == 0 and count[n] >= 3:
                    ans.append([n]*3)
                else:
                    comp = -2*n
                    if comp in count and comp != n:
                        ans.append([n]*2 + [comp])
            if n < 0:
                twosum = -n
                left = bisect.bisect_left(nums, twosum - nums[-1], i+1)
                right = bisect.bisect_right(nums, twosum // 2, left)
                for j in nums[left:right]:
                    comp = twosum - j
                    if comp in count and comp != j:
                        ans.append([n,j,comp])
        return ans
__________________________________________________________________________________________________
248ms
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if not nums: return []
        count = {}
        for n in nums:
            if n not in count:
                count[n] = 0
            count[n] += 1
        ans = []
        nums = sorted(count)
        for i, n in enumerate(nums):
            if count[n] >= 2:
                if n == 0 and count[n] >= 3:
                    ans.append([n] * 3)
                else:
                    comp = (-2 * n)
                    if comp in count and comp != n:
                        ans.append([n] * 2 + [comp])
            if n < 0:
                twoSum = -n
                left = bisect.bisect_left(nums, twoSum - nums[-1], i + 1)
                right = bisect.bisect_right(nums, twoSum // 2, left)
                for j in nums[left:right]:
                    comp = twoSum - j
                    if comp in count and comp != j:
                        ans.append([n, j, comp])
        return ans
__________________________________________________________________________________________________
252ms
class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        """if len(nums) == 0:
            return []
        
        nums.sort()
        res = []"""
        
        """
        for i in range(0, len(nums)):
            j = i + 1
            k = len(nums) - 1
            while (j < k):
                if (nums[i] + nums[j] + nums[k] == 0):
                    ans = [nums[i], nums[j], nums[k]]
                    if ans not in res:
                        res.append(ans[:])
                    ans = []
                    j += 1
                    k -= 1
                elif (nums[i] + nums[j] + nums[k] > 0):
                    k -= 1
                else:
                    j += 1
        return res"""
 
        """for i in range(0, len(nums)):
            if (i != 0 and nums[i] == nums[i - 1]): continue
            j = i + 1 
            k = len(nums) - 1 
            while(j < k):
                if(nums[i] + nums[j] + nums[k] == 0):
                    res.append([nums[i], nums[j], nums[k]])
                    j += 1 
                    while(j < k and nums[j] == nums[j - 1]): j += 1 
                elif(nums[i] + nums[j] + nums[k] > 0):
                    k -= 1 
                    
                else:
                    j += 1 
        return res"""
        if not nums: return []
        count = {}
        for n in nums:
            if n not in count:
                count[n] = 0
            count[n] += 1
        ans = []
        nums = sorted(count)
        for i,n in enumerate(nums):
            if count[n] >= 2:
                if n == 0 and count[n] >= 3:
                    ans.append([n]*3)
                else:
                    comp = -2*n
                    if comp in count and comp != n:
                        ans.append([n]*2 + [comp])
            if n < 0:
                twosum = -n
                left = bisect.bisect_left(nums, twosum - nums[-1], i+1)
                right = bisect.bisect_right(nums, twosum // 2, left)
                for j in nums[left:right]:
                    comp = twosum - j
                    if comp in count and comp != j:
                        ans.append([n,j,comp])
        return ans
__________________________________________________________________________________________________
15420 kb
class Solution:
    def threeSum(self, nums: 'List[int]') -> 'List[List[int]]':
        if not nums:
            return []
        nums.sort()
        result = set()
        for i in range(len(nums)):
            l = i+1
            r = len(nums)-1
            while l < r:
                tmp = nums[i] + nums[l] + nums[r]
                if tmp == 0:
                    result.add((nums[i], nums[l], nums[r]))
                    l += 1
                    r -= 1
                elif  tmp > 0:
                    r -= 1
                else:
                    l += 1
                    
        return list(result)                
__________________________________________________________________________________________________
15536 kb
class Solution:
    def threeSum(self, nums: 'List[int]') -> 'List[List[int]]':
        triplets = set([])
        nums = sorted(nums)
        print(nums)
        j = len(nums) - 1
        N = len(nums)
        for i in range(0, N-2):
            j = len(nums) -1
            k  = i + 1
            while(k < j):
                #print(i,j,k)
                sum3 = nums[i] + nums[k] + nums[j]
                if sum3 > 0:
                    j -= 1
                elif sum3 == 0:
                    triplets.add((nums[i], nums[k], nums[j]))
                    k += 1
                else:
                    k += 1
        return list(triplets)
__________________________________________________________________________________________________
