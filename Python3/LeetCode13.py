__________________________________________________________________________________________________
60ms
class Solution:
    def romanToInt(self, s):
        m = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000,
        }

        last = m[s[0]]
        total = 0

        for c in s[1:]:
            n = m[c]
            total += last if n <= last else -last
            last = n
        
        return total + last
__________________________________________________________________________________________________
64ms
class Solution:
    def romanToInt(self, s: str) -> int:
        if not s:
            return 0
        dic = {
            'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000
        }
        ret = 0
        n = len(s)
        
        for i in range(n-1):
            if dic[s[i]]<dic[s[i+1]]:
                ret -=dic[s[i]]
            else:
                ret+=dic[s[i]]
        return ret+dic[s[-1]]        
__________________________________________________________________________________________________
68ms
from itertools import islice, zip_longest
class Solution:
    def romanToInt(self, s: str) -> int:
        vals = {
            None: 0,
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000,
        }
        val = 0
        for cur, nxt in zip_longest(s, islice(s, 1, None)):
            if vals[cur] >= vals[nxt]:
                val += vals[cur]
            else:
                val -= vals[cur]
            
        return val           
__________________________________________________________________________________________________
12344 kb 
class Solution:
    def romanToInt(self, s: 'str') -> 'int':
        roman = {
            'M': 1000,
            'D': 500,
            'C': 100,
            'L': 50,
            'X': 10,
            'V': 5,
            'I': 1
        }
        
        total = 0
        for i in range(len(s) - 1):
            if roman[s[i]] < roman[s[i+1]]:
                total -= roman[s[i]]
            else:
                total += roman[s[i]]
        return total + roman[s[-1]]
__________________________________________________________________________________________________
12356 kb
class Solution:
    def romanToInt(self, s: 'str') -> 'int':
        roman_to_int = {
            'I':1,
            'V':5,
            'X':10,
            'L':50,
            'C':100,
            'D':500,
            'M':1000,
            'IV':4,
            'IX':9,
            'XL':40,
            'XC':90,
            'CD':400,
            'CM':900,
        }
        result = 0
        last_two = ''
        for roman_num in s:
            last_two += roman_num
            if len(last_two) == 2:
                if last_two in roman_to_int:
                    result += roman_to_int[last_two]
                    last_two = ''
                else:
                    result += roman_to_int[last_two[0]]
                    last_two = last_two[1]
        if last_two:
            result += roman_to_int[last_two]
        return result
__________________________________________________________________________________________________
