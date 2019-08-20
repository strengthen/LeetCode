__________________________________________________________________________________________________
sample 108 ms submission
class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        s=list(map(len,s.replace('10','1 0').replace('01','0 1').split(' ')))
        #print(list(s))
        return sum(min(a,b) for a,b in zip(s,s[1:]))
__________________________________________________________________________________________________
sample 13132 kb submission
class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        ret, prev, cur = 0, 0, 1
        for i in range(1, len(s)):
            if s[i-1] != s[i]:
                ret += min(prev, cur)
                prev, cur = cur, 1
            else:
                cur += 1

        return ret + min(prev, cur)
__________________________________________________________________________________________________
