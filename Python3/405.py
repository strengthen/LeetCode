__________________________________________________________________________________________________
sample 16 ms submission
class Solution:
    def toHex(self, num: int) -> str:
        if num == 0: return '0'
        x = num.to_bytes(4, byteorder='big', signed=True).hex()
        count = 0
        for i in x:
            if i == '0':
                count += 1
            else:
                break
        return x[count:]                
__________________________________________________________________________________________________
sample 13152 kb submission
class Solution:
    def toHex(self, num: int) -> str:
        ans = ''
        if num < 0:
            num = 0x100000000 + num
        while num > 0:
            digit = num % 16
            if digit < 10:
                ans = chr(ord('0') + digit) + ans
            else:
                ans = chr(ord('a') + digit - 10) + ans
            num //= 16
            
        if len(ans) == 0:
            return '0'
        else:
            return ans
__________________________________________________________________________________________________
