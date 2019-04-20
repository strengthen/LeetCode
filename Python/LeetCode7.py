__________________________________________________________________________________________________
24ms
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        x = str(x)
        upper_bound = (1 << 31)-1
        neg_flag = 1
        if x[0] == '-':
            neg_flag = -1
            x = x[1:]
        if x[0]== '+':
            x= x[1:]
        temp =     int(x[::-1])
        if temp >=upper_bound:
            temp = 0
        return neg_flag* temp
__________________________________________________________________________________________________
28ms
import math
class Solution(object):
    def reverse(self, x):
        ret = 0
        mul = 1
        sign = x/abs(x) if x is not 0 else 0
        log = int(math.log(abs(x))/math.log(10)) if x is not 0 else 0
        #maxmul = 10**log if x is not 0 else 0
        for mul in [10**d for d in range(log + 1)]:
            ret += (10**log)*(sign*((abs(x)/mul)%10))
            log -= 1        
        return ret if ret<=2**31-1 and ret >= -(2**31) else 0
        """
        :type x: int
        :rtype: int
        """
__________________________________________________________________________________________________
32ms
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        absoluteX = abs(x)
        isNegative = absoluteX != x
        
        split_int = list(str(absoluteX))
        left_index = 0
        right_index = len(split_int) - 1
        
        while left_index < right_index :
            split_int[left_index], split_int[right_index] = split_int[right_index],                 split_int[left_index]
            
            left_index += 1
            right_index -= 1
        
        combined_int = int(''.join(split_int))
        
        if(abs(combined_int) > (2 ** 31 - 1)) :
            return 0
        
        if isNegative :
            combined_int = combined_int * -1
            
        return combined_int
__________________________________________________________________________________________________
10412 kb
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        INT_MAX = 2**31 -1
        print(INT_MAX)
        
        sign  = -1 if (x<0) else 1
        x_abs = abs(x)
        
        # inverse
        x_inv = int(str(x_abs)[::-1])
        
        # limits
        return x_inv*sign if x_inv<=INT_MAX else 0
__________________________________________________________________________________________________
10488 kb
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x == 0:
            return 0
        result = str(x)
        result = result[::-1].lstrip("0")
        if result[-1] == '-':
            result = result.strip('-')
            result = '-' + result
        return int(result) if int(result) < (2**31 - 1) and int(result) > (-2)**31 else 0
__________________________________________________________________________________________________
