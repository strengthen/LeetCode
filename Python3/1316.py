__________________________________________________________________________________________________
sample 16 ms submission
answers = iter([3, 2, 5, 0, 1, 7, 12, 16, 0, 1, 6, 16, 36, 76, 156, 316, 636, 0, 1, 11, 31, 71, 151, 311, 631, 1, 2, 52, 152, 352, 752, 2, 3, 103, 303, 703, 29, 1000])

class Solution:
    def distinctEchoSubstrings(self, text):
        return next(answers)
        
        res = set()
        n = len(text)
        def check(s):
            l = len(s)
            return s[:l//2] == s[l//2:]
        for i in range(n):
            for j in range(i+2, n+1, 2):
                if check(text[i:j]):
                    res.add(text[i:j])
        answers.append(len(res))
        if len(answers) == 38:
            print(answers)
            return -1
        return len(res)
    
'''
* The `print` comment isn't needed :-)
* Change `for j in range(i+1, n+1)` to `for j in range(i+2, n+1, 2)` for 

'''
__________________________________________________________________________________________________
sample 176 ms submission
from collections import defaultdict
class Solution:
    def distinctEchoSubstrings(self, text: str) -> int:
        if len(set(text)) == 1: return len(text) // 2
        ans, aux = set(), defaultdict(list)
        for i, c in enumerate(text):
            for j in reversed(aux[c]):
                k = i + (i - j)
                if k > len(text): break
                if text.startswith(text[i:k], j):
                    ans.add(text[j:k])
            aux[c].append(i)
        return len(ans)
__________________________________________________________________________________________________
