__________________________________________________________________________________________________
class Solution:
    def maximum69Number (self, num: int) -> int:
        for idx in range(len(str(num))):
            if str(num)[idx]=='6':
                return int(str(num)[:idx]+'9'+str(num)[idx+1:])
        return num
__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def maximum69Number (self, num: int) -> int:
        num_str = list(str(num))
        for i, ch in enumerate(num_str):
            if ch == '6':
                num_str[i] = '9'
                break
        return int(''.join(num_str))
__________________________________________________________________________________________________
