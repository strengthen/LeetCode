__________________________________________________________________________________________________
sample 12 ms submission
class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        def get_seq(start, digits):
            res, i = 0, start
            for i in range(digits):
                res *= 10
                res += start
                start += 1
            return res
        
        def count_digits(num):
            c = 0
            while num > 0:
                num //= 10
                c += 1
            return c
        
        l_digits = count_digits(low)
        h_digits =  count_digits(high)
        ans = []
        for digit in range(l_digits, h_digits+1):            
            for i in range(1,10-digit+1):
                n = get_seq(i, digit)
                
                if n >= low and n <= high:
                    ans.append(n)
        return ans
__________________________________________________________________________________________________
sample 16 ms submission
class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        ans=[12,23,34,45,56,67,78,89,123,234,345,456,567,678,789,1234,2345,3456,4567,5678,6789,12345,23456,34567,45678,56789,123456,234567,345678,456789,1234567,2345678,3456789,12345678,23456789,123456789]
        result=[]
        for i in range(0,len(ans)):
            if ans[i]>=low and ans[i]<=high:
                result.append(ans[i])
        return result
__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def getLen(self, n):
        result = 0
        while n > 0:
            n = (n - (n % 10)) / 10
            result += 1
        
        return result
        
    def getDigits(self, s, n):
        digits = [1,2,3,4,5,6,7,8,9]
        if s + n > 10:
            return 0
        else:
            return sum(v * (10 ** (n-i-1)) for i, v in enumerate(digits[s-1:s+n-1]))
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        result = []
        len_min = self.getLen(low)
        len_max = self.getLen(high)
            
        for l in range(len_min, len_max+1):
            for s in range(1, 10):
                number = self.getDigits(s, l)
                if low <= number <= high:
                    result.append(number)
                    
        return result