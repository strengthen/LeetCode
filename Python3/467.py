__________________________________________________________________________________________________
sample 72 ms submission
from collections import defaultdict
class Solution:
    def findSubstringInWraproundString(self, p: str) -> int:
        """
        dp[i]: longest subsequence that ends at index i
        dp[i] = 1 if i == 0 or dp[i] != dp[i - 1] (in ord) else dp[i - 1] + 1
        """
        
        prevchar = {a : b for a, b in zip(string.ascii_lowercase, 'z' + string.ascii_lowercase[:-1])}
        longest_end_as = defaultdict(int)
        res = 0
        length = 0
        
        for i, c in enumerate(p):
            if i == 0 or p[i - 1] != prevchar[c]:
                length = 1
            else:
                length += 1
            if length > longest_end_as[c]:
                res += length - longest_end_as[c]
                longest_end_as[c] = length
        
        return res
__________________________________________________________________________________________________
sample 76 ms submission
from collections import defaultdict
class Solution:
    def findSubstringInWraproundString(self, p: str) -> int:
        if not p: return 0
        n = len(p)
        count = 1
        seq = "abcdefghijklmnopqrstuvwxyz"
        next_d = {seq[i]: seq[(i+1)%len(seq)] for i in range(len(seq))}
        d_max_length = defaultdict(int) # d['a'] = max length substring ending with 'a'
        for i in range(n):
            if i < n-1 and p[i+1] == next_d[p[i]]:
                count += 1
            else:
                # p[i-count+1 : i+1] is a substring of length count
                for j in range(min(count, len(seq))):
                    # decrease the substring length and check each end
                    end_c = p[i-j]
                    if d_max_length[end_c] < count - j:
                        d_max_length[end_c] = count - j
                    else:
                        # all shorter sequence should have larger values already
                        break
                count = 1
        res = sum(d_max_length.values())
        return int(res)
__________________________________________________________________________________________________
