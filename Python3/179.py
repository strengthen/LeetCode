__________________________________________________________________________________________________
sample 32 ms submission
class LargerNumKey(str):
    def __lt__(x, y):
        return x+y > y+x
        
class Solution:
    def largestNumber(self, nums):
        largest_num = ''.join(sorted(map(str, nums), key=LargerNumKey))
        return '0' if largest_num[0] == '0' else largest_num
__________________________________________________________________________________________________
sample 13076 kb submission
class largerNum(str):
    def __lt__(x, y):
        return x+y > y+x
    
class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        largest_num = ''.join(sorted(map(str, nums), key=largerNum))
        return '0' if largest_num[0] == '0' else largest_num
__________________________________________________________________________________________________
