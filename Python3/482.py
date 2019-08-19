__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def licenseKeyFormatting(self, S: str, K: int) -> str:
        
        S=''.join(S.split('-')).upper()
        result=[]
        s=len(S)%K
        n=len(S)//K
        if s>0:
            result.append(S[:s])
        for i in range(1,n+1):
            result.append(S[s+(i-1)*K:s+i*K])
        return '-'.join(result)
__________________________________________________________________________________________________
sample 13392 kb submission
class Solution:
    def licenseKeyFormatting(self, S: str, K: int) -> str:
        ret = ''
        count = 0
        for i in range(len(S) - 1, -1, -1):
            char = S[i].upper()
            if char == '-':
                continue
            if count > 0 and count % K == 0:
                ret = '-' + ret
                count = 0
            ret = char + ret
            count += 1
        return ret
__________________________________________________________________________________________________
