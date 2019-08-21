__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def maskPII(self, S: str) -> str:
        at=S.find('@')
        if at>0:
            return (S[0]+'*****'+S[at-1:]).lower()
        S=''.join([i for i in S if i.isdigit()])
        return ["", "+*-", "+**-", "+***-"][len(S) - 10] + "***-***-" + S[-4:]
__________________________________________________________________________________________________
sample 28 ms submission
import re
class Solution:
    def maskPII(self, S):
        if '@' in S:
            S = S.lower()
            res = S.split('@')
            return res[0][0] + '*****' + res[0][-1] + '@' + res[1]
        else:
            S = S.replace('(', '').replace(')', '').replace('-', '').replace('+', '').replace('-', '').replace(' ', '')
            if len(S) == 10:
                return '***-***-' + S[6:]
            else:
                return '+' + (len(S) - 10) * '*' + '-***-***-' + S[-4:]
    def maskPII1(self, S: str) -> str:
        if len(S) >= 2 and re.match(r'[a-zA-Z]+\@[a-zA-Z]+\.[a-zA-Z]+', S):
            S = S.lower()
            first = S[0]
            second = S[S.find('@') - 1]
            rest = S[S.find('@'):]
            return f'{first}*****{second}{rest}'
        else:
            S = S.replace('(', '').replace(')', '').replace('-', '').replace('+', '').replace('-', '').replace(' ', '')
            if len(S) == 10:
                ans = ['***', '***', S[6:]]
                return '-'.join(ans)
            elif len(S) == 11:
                ans = ['+*', '***', '***', S[-4:]]
                return '-'.join(ans)
            elif len(S) == 12:
                ans = ['+**', '***', '***', S[-4:]]
                return '-'.join(ans)
            elif len(S) == 13:
                ans = ['+***', '***', '***', S[-4:]]
                return '-'.join(ans)
            return S
__________________________________________________________________________________________________
