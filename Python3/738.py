__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def monotoneIncreasingDigits(self, N: int) -> int:
        strs = list(str(N))
        n = len(strs)
        index = n - 1
        for i in range(1,n):
            if strs[i] < strs[i-1]:
                index = i-1
                break
        if index == n-1:
            return N
        while index> 0 and strs[index-1] == strs[index]:
            index -= 1
        strs[index] = str(int(strs[index]) - 1)
        index += 1
        while index < n:
            strs[index]  = '9'
            index += 1
        return int(''.join(strs))
__________________________________________________________________________________________________
sample 13112 kb submission
class Solution:
    def monotoneIncreasingDigits(self, N: int) -> int:
        s = list(str(N))
        i = 1
        while i < len(s) and s[i-1] <= s[i]:
            i+=1
        while 0 < i < len(s) and s[i-1] > s[i]:
            s[i-1] = str(int(s[i-1]) - 1)
            i-=1
        s[i+1:] = '9' * (len(s) - i -1)
        return int(''.join(s))
__________________________________________________________________________________________________
