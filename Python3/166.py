__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        ans = "-" if numerator*denominator<0 else ""
        numerator = abs(numerator)
        denominator = abs(denominator)
        q, r = numerator//denominator, numerator%denominator
        ans += str(q)
        if r!=0:
            ans += "."
        spos = len(ans)
        digits = dict()
        stat = False
        while r!=0:
            r *= 10
            q, r = r//denominator, r%denominator
            if (q,r) in digits:
                stat = True
                break
            digits[q,r] = spos
            spos += 1
            ans += str(q)
        if stat:
            ans = ans[:digits[q,r]] + "(" + ans[digits[q,r]:] + ")"
        return ans
__________________________________________________________________________________________________
sample 13148 kb submission
class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        sign = '-' if numerator*denominator < 0 else ''
        nume, deno = abs(numerator), abs(denominator)
        n, remainder = divmod(nume, deno)
        result = [sign+str(n), '.']
        stack = []
        while remainder not in stack:
            stack.append(remainder)
            n, remainder = divmod(remainder*10, deno)
            result.append(str(n))
            
        idx = stack.index(remainder)
        result.insert(idx+2, '(')
        result.append(')')
        return ''.join(result).replace('(0)', '').rstrip('.')
__________________________________________________________________________________________________
