__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        to_compare, second = "", ""
        for c in S:
            if c == '#':
                if to_compare:
                    to_compare = to_compare[:-1]
            else:
                to_compare += c

        for c in T:
            if c == '#':
                if second:
                    second = second[:-1]
            else:
                second += c

        return second == to_compare        
__________________________________________________________________________________________________
sample 13024 kb submission
class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        w = 0
        S = list(S)
        for i in range(len(S)):
            if S[i] == "#":
                w = w - 1 if w > 1 else 0
            else:
                S[w] = S[i]
                w += 1
        
        while w < len(S):
            S.pop()
        
        w = 0
        T = list(T)
        for i in range(len(T)):
            if T[i] == "#":
                w = w - 1 if w > 1 else 0
            else:
                T[w] = T[i]
                w += 1
        
        while w < len(T):
            T.pop()

        return S == T        
__________________________________________________________________________________________________
