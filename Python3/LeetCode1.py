__________________________________________________________________________________________________
32ms
class Solution:
    def twoSum(self, nums: 'List[int]', target: 'int') -> 'List[int]':
        dict = {}
        for i, num in enumerate(nums):
            dict[num] = i
            
        for i, num in enumerate(nums):
            if target - num in dict and i != dict[target - num]:
                return [i, dict [target - num]]
__________________________________________________________________________________________________
36ms
class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        record = dict()
        for i in range(len(nums)):
            if nums[i] in record:
                return [record[nums[i]], i]
            record[target-nums[i]] = i
        return [-1, -1]
__________________________________________________________________________________________________
40ms
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for i in range(len(nums)):
            t = target - nums[i]
            if t in d.keys():
                return([d[t],i])
            d[nums[i]]=i
__________________________________________________________________________________________________
44ms
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dic = {}
        for i in range(len(nums)):
            dic[target-nums[i]] = i
        for j in range(len(nums)):
            if nums[j] in dic and j!=dic[nums[j]]:
                return [j, dic[nums[j]]]
__________________________________________________________________________________________________
12496 kb
class Solution:
    def twoSum(self, nums: 'List[int]', target: 'int') -> 'List[int]':
        resultList=[]
        for index,element in enumerate(nums):
           for y in range(index+1,len(nums)):
               if nums[index]+nums[y]==target:
                   resultList.append(index)
                   resultList.append(y)
        return resultList
__________________________________________________________________________________________________
