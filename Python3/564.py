__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def nearestPalindromic(self, S: str) -> str:
        K = len(S)
        candidates = [str(10**k + d) for k in (K-1, K) for d in (-1, 1)]
        prefix = S[:(K+1)//2]
        P = int(prefix)
        for start in map(str, (P-1, P, P+1)):
            candidates.append(start + (start[:-1] if K%2 else start)[::-1])

        def delta(x):
            return abs(int(S) - int(x))

        ans = None
        for cand in candidates:
            if cand != S and not cand.startswith('00'):
                if (ans is None or delta(cand) < delta(ans) or
                        delta(cand) == delta(ans) and int(cand) < int(ans)):
                    ans = cand
        return ans        
__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def nearestPalindromic(self, n):
        """
        :type n: str
        :rtype: str
        """
        if len(n)==1:
            if n=='0':
                return '1'
            else:
                return str(int(n)-1)
        origi=int(n)
        candidate=[]
        left=n[:len(n)//2]
        left_num=int(left)
        l=len(n)
        odd= l%2==1
        if left=='1'+'0'*(l//2-1):
            low='9'*(l-1)
        else:
            low=str(left_num-1)
            if not odd:
                low=low+low[::-1]
            else:
                low=low+'9'+low[::-1]
        candidate=[low,origi-int(low)]
        if odd and n[l//2]!='0':
            med_low=left+str(int(n[l//2])-1)+left[::-1]
            diff=origi-int(med_low)
            if diff<candidate[1]:
                candidate=[med_low,diff]
        
        if not odd:
            med=left+left[::-1]
        else:
            med=left+n[l//2]+left[::-1]
        if med!=n:
            diff=abs(int(med)-origi)
            if diff<candidate[1]:
                candidate=[med,diff]
        if odd and n[l//2]!='9':
            med_high=left+str(int(n[l//2])+1)+left[::-1]
            diff=int(med_high)-origi
            if diff<candidate[1]:
                return med_high
    
        if left=='9'*(l//2):
            high='1'+'0'*(l-1)+'1'
        else:
            high=str(left_num+1)
            if not odd:
                high=high+high[::-1]
            else:
                high=high+'0'+high[::-1]
        diff=int(high)-origi
        if diff<candidate[1]:
            candidate=[high,diff]
      
        return candidate[0]
__________________________________________________________________________________________________
