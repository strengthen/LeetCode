__________________________________________________________________________________________________
56ms
class Solution:
    def intToRoman(self, num: int) -> str:
        res = ''
         
        return self.toPartRom(num//1000, 'M--') + \
            self.toPartRom((num % 1000)//100, 'CDM') + \
            self.toPartRom((num % 100)//10, 'XLC') + \
            self.toPartRom(num % 10, 'IVX')
    
    def toPartRom(self, n : int, subs: str) -> str:
        
        if n == 0:
            return ''
        
        if n <= 3:
            return subs[0] * n
        if n == 4:
            return subs[0] + subs[1]
        if n <= 8:
            return subs[1] + subs[0]* (n - 5)
        if n == 9:
            return subs[0] + subs[2]
__________________________________________________________________________________________________
60ms
class Solution:
    def intToRoman(self, num: int) -> str:
        memo = {1000: 'M', 500: 'D',
               100: 'C', 50: 'L',
               10:'X', 5: 'V', 1: 'I'}
        res = []
        for it in [1000,100,10,1]:
            ##
            a = num//it
            num = num%it
            if a == 9:
                res.append(memo[it])
                res.append(memo[it*10])
            elif a==4:
                res.append(memo[it])
                res.append(memo[it*5])
            elif a==5:
                res.append(memo[it*5])
            elif a<4:
                res += [memo[it]]*a
            else:
                res.append(memo[it*5])
                res+=[memo[it]]*(a-5)
        return ''.join(res)
__________________________________________________________________________________________________
64ms
class Solution:
    def intToRoman(self, num: int) -> str:
        #table = {"IV" : 4, "IX" : 9, "XL" : 40, "XC" : 90, "CD" : 400, "CM" : 900, "I" : 1, "V" : 5, "X" : 10, "L" : 50, "C" : 100, "D" : 500, "M" : 1000}
        
        table = {1 : "I", 5 : "V", 10 : "X", 50 : "L", 100 : "C", 500 : "D", 1000 : "M", 4 : "IV", 9 : "IX", 40 : "XL", 90 : "XC", 400 : "CD", 900 : "CM"}

        vals = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        
        solution = []
        for v in vals:
            while num - v >= 0:
                num -= v
                solution.append(table[v])
                    
        return ''.join(solution)            
__________________________________________________________________________________________________
12352 kb
class Solution:
    def intToRoman(self, num: 'int') -> 'str':
        values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        symbols = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I']
        result = ''
        for symbol, value in zip(symbols, values):
            result += symbol * (num // value)
            num %= value
        return result
__________________________________________________________________________________________________
12392 kb
class Solution:
    def intToRoman(self, num: 'int') -> 'str':
        result = []
        roman = {0:'', 1:'I', 2:'II', 3:'III', 4:'IV', 5:'V', 6:'VI', 7:'VII', 8:'VIII', 9:'IX', 10:'X', 20:'XX', 30:'XXX', 40:'XL', 50:'L', 60:'LX', 70:'LXX', 80:'LXXX', 90:'XC', 100:'C', 200:'CC', 300:'CCC', 400:'CD', 500:'D', 600:'DC', 700:'DCC', 800:'DCCC', 900:'CM', 1000:'M', 2000:'MM', 3000:'MMM'}

        thousands = num//1000*1000
        hundreds = (num-thousands)//100*100
        tens = (num-thousands-hundreds)//10*10
        ones = (num-thousands-hundreds-tens)
        print("thousands: {}".format(thousands), "hundreds: {}".format(hundreds),
             "tens: {}".format(tens), "ones: {}".format(ones), sep='\n')
        
        result += (roman[thousands] + roman[hundreds] + roman[tens]+ roman[ones])
        return ''.join(result)
__________________________________________________________________________________________________
