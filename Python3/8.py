__________________________________________________________________________________________________
44ms
class Solution:
    def myAtoi(self, str: str) -> int:
        first, smb, num = True, 1, ""
        intMin, intMax = -2147483648, 2147483647
        for i in str:
            if i == ' ' and first:
                continue
            if first:
                first = False
                if i == '+':
                    continue
                elif i == '-':
                    smb = -1
                    continue
            if i.isdigit():
                num += i
                if int(num) == 0:
                    num = ""
            else:
                break
            if len(num) >= 11:
                break
        if num:
            ans = int(num)*smb
            if ans < intMin:
                ans = intMin
            elif ans > intMax:
                ans = intMax
        else:
            ans = 0
        return ans
__________________________________________________________________________________________________
48ms
class Solution:
    def myAtoi(self, strs: str) -> int:
        strs = strs.strip()
        if len(strs) == 0:
            print('A')
            return 0
        print(strs)
        
        flag0 = 0
        flag1 = 0
        try:            
            int(strs[1])
            flag1 = 1
            
        except:
            print('pass')
            
        try:
            int(strs[0])
            flag0 = 1
        except:
            print('pass')

        if not flag0:
            print('B')
            if strs[0]!= '+' and strs[0]!= '-':
                print('C')
                return 0
            else:
                print('g')
                if flag1:
                    print('D')
                    n = 1
                    flag = 1
                    num = strs[0]
                    while n <len(strs) and flag:
                        try:
                            int(strs[n])
                            num = num+strs[n]
                            n = n+1
                        except:
                            flag = 0
                else:
                    print('E')
                    return 0                    
        else:
            print('F')
            n = 1
            flag = 1
            num = strs[0]
            while n <len(strs) and flag:
                try:
                    int(strs[n])
                    num = num+strs[n]
                    n = n+1
                except:
                    flag = 0
                        
        
        INT_MAX = 2**31-1
        INT_MIN = -2**31
        if int(num)>INT_MAX :
            return INT_MAX
        elif int(num)<INT_MIN:
            return INT_MIN
        else:
            return int(num)
__________________________________________________________________________________________________
52ms
MAX_INT = (2**31)-1
MIN_INT = -2**31
digits = {
    '0': 0,
    '1': 1,
    '2': 2,
    '3': 3,
    '4': 4,
    '5': 5,
    '6': 6,
    '7': 7,
    '8': 8,
    '9': 9
}

class Solution:
    def myAtoi(self, s: str) -> int:
        neg = False
        found_sign = False
        val = 0
        for c in s:
            print(c, found_sign, neg)
            if c == "+":
                if found_sign:
                    break
                found_sign = True
                continue
            elif c == "-":
                if found_sign:
                    break
                neg = not neg
                found_sign = True
                continue
            elif c == " ":
                if val > 0 or found_sign:
                    break
                continue
            elif c in digits:
                found_sign = True
                val *=10
                val += digits[c]
            else:
                break
                
        if neg:
            val *= -1
            
        if val < MIN_INT:
            val = MIN_INT
            
        if val > MAX_INT:
            val = MAX_INT

        return val
__________________________________________________________________________________________________
12244 kb 
class Solution:
    def myAtoi(self, s: 'str') -> 'int':
        s = s.strip()
        sign = 1
        if not s:
            return 0
        if s[0] in ["+","-"]:
            if s[0] == "-":
                sign = -1
            s = s[1:]
        ans = 0
        for c in s:
            if c.isdigit():
                 ans = ans * 10 + int(c)
            else:
                break
        ans *= sign
        if ans > 2**31-1:
            return 2**31-1
        elif ans < -2**31:
            return -2**31
        else:
            return ans
__________________________________________________________________________________________________
12280 kb
class Solution:
    def myAtoi(self, str: 'str') -> 'int':
        sum = 0
        res = 0
        flag = 0
        start = 0
        str = str.strip()
        li = list(str)
        if len(li) == 0: 
            return 0
        if li[0] == "+":
            start = 1
        elif li[0] == "-":
            flag = 1
            start = 1
            
        for i in range(start, len(li)):
            if not li[i].isdigit(): 
                break
            else: 
                res *= 10
                res += int(li[i])
            
        if flag == 0: return min(res, 2 ** 31 - 1)
        else: return max(-res, -2 ** 31)
__________________________________________________________________________________________________
