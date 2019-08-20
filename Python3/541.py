__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        return self.helper(s, k, 1)
    def helper(self, s, k, num):
        if s == "":
            return ""
        res = ""
        if num % 2 == 0:
            res += s[:k]
            res += self.helper(s[k:], k, num + 1)
        else:
            res += s[:k][::-1]
            res += self.helper(s[k:], k, num + 1)
        return res        
__________________________________________________________________________________________________
sample 13204 kb submission
class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        s = list(s)
        for i in range(0, len(s), 2*k):
            s[i:i+k] = reversed(s[i:i+k])
        return "".join(s)
__________________________________________________________________________________________________
