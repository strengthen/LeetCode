__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def camelMatch(self, queries, pattern):
        def match(q, pattern):
            pi = 0
            for c in q:
                if pi < len(pattern) and c == pattern[pi]:
                    pi += 1
                elif c.isupper():
                    return False
            return pi == len(pattern)

        lp = len(pattern)
        return [False if len(q) < lp else match(q, pattern) for q in queries]
__________________________________________________________________________________________________
sample 13084 kb submission
class Solution:
    def camelMatch(self, queries: List[str], pattern: str) -> List[bool]:
        def match(s, p):
            i = j = 0
            while i < len(s) and j < len(p):
                if s[i].isupper() and p[j].isupper():
                    if s[i] != p[j]:
                        return False
                    i, j = i + 1, j + 1
                elif s[i].islower() and p[j].islower():
                    if s[i] != p[j]:
                        i += 1
                    else:
                        i, j = i + 1, j + 1
                elif s[i].islower():
                    i += 1
                else:
                    return False
            return j == len(p) and not any(ch.isupper() for ch in s[i:])
        return [match(q, pattern) for q in queries]
__________________________________________________________________________________________________
