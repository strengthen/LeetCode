__________________________________________________________________________________________________
32ms
class Solution:
    def twoSum(self, nums: 'List[int]', target: 'int') -> 'List[int]':
        dict = {}
        for i, num in enumerate(nums): # enumerate()函数用于将一个可遍历的数据对象(如列表、元组或字符串)组合为一个索引序列，
        # 同时列出数据和数据下标，一般用在 for 循环当中。i和num,默认前面一个是索引，后面一个是对象里的内容
            dict[num] = i # 键值对，num是键，i是值，赋予给num键。
            
        for i, num in enumerate(nums):
            if target - num in dict and i != dict[target - num]: # 是判断键（key）在不在dict里面
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
