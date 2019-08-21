__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def reorganizeString(self, S: str) -> str:
        tmp = []
        for c, x in sorted((S.count(x), x) for x in set(S)):
            if c > (len(S)+1)/2:
                return ''
            tmp += [x] *c
        # print(tmp)
        # print(tmp[:len(S)//2+1])
        res = [None] * len(S)
        res[::2], res[1::2] = tmp[len(S)//2:], tmp[:len(S)//2]
        return ''.join(res)
__________________________________________________________________________________________________
sample 13080 kb submission
from collections import Counter
class Solution:
    def reorganizeString(self, S: str) -> str:
        if len(S) == 0:
            return ""
        elif len(S) == 1:
            return S
        _counter = Counter(S).most_common()
        print(_counter)
        if Counter(S).most_common(1)[0][1] > (len(S) + 1) // 2:
            return ""
        _res = [""]*len(S)
        _index = 0
        _left_over = []
        for letter, count in _counter:
            for _ in range(count):
                if _index < len(S):
                    _res[_index] = letter
                    _index += 2
                else:
                    _left_over.append(letter)
        _start = 1
        for letter in _left_over:
            _res[_start] = letter
            _start += 2
        return "".join(_res)
__________________________________________________________________________________________________
