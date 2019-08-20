__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def nextGreaterElement(self, n: int) -> int:
        s = list(map(int, list(str(n))))
        i = len(s)-1
        while i-1 >=0 and s[i] <= s[i-1]:
            i-=1
        if i == 0:
            return -1
        j = i-1
        mini = [x for x in s[i:] if x > s[j]]
        if not mini:
            return -1
        
        a = min(mini)
        for w in range(len(s)-1,-1,-1):
            if s[w] == a:
                break
        s[j] , s[w] = s[w] , s[j]
        s[:] = s[:i] + sorted(s[i:])
        ret = int("".join(map(str,(s)))) 
        return ret if ret<=((1<<31)-1) else -1
__________________________________________________________________________________________________
sample 12980 kb submission
class Solution:
    def nextGreaterElement(self, n: int) -> int:
        d = list(str(n))
        n = len(d)
        i, j = n-2, n-1
        while i >= 0 and d[i+1] <= d[i]: i -= 1
        if i == -1: return -1
        while d[j] <= d[i]: j -= 1
        d[i], d[j] = d[j], d[i]
        res = int(''.join(d[:i+1] + d[i+1:][::-1]))
        if res >= 2**31 or res == n: return -1
        return res
__________________________________________________________________________________________________
