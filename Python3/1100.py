__________________________________________________________________________________________________
class Solution:
    def numKLenSubstrNoRepeats(self, S: str, K: int) -> int:
        i, j = 0, K-1, 
        
        cnt = collections.Counter(S[i:j+1])
        print(cnt)
        if K > len(S):
            return 0
        res = 0
        for _ in range(len(S) - K+1):
            if len(cnt) == K:
                res += 1
            if j + 1 < len(S):
                cnt[S[j+1]] += 1
            cnt[S[i]] -= 1
            if cnt[S[i]] == 0:
                del cnt[S[i]]
            j += 1
            i += 1
        return res        
__________________________________________________________________________________________________

__________________________________________________________________________________________________
