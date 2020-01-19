__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def printVertically(self, s: str) -> List[str]:
        s = s.split(" ")
        n = max(len(string) for string in s)
        ans = [[] for i in range(n)]
        for string in s:
            i = 0
            for i, S in enumerate(string):
                ans[i].append(S)
            for j in range(i + 1, n):
                ans[j].append(" ")
        for a in ans:
            while a and a[-1] == " ":
                a.pop()
        return ["".join(a) for a in ans]
__________________________________________________________________________________________________
class Solution:
    def printVertically(self, s: str) -> List[str]:
        import itertools
        return  ["".join(x).rstrip() for x in list(itertools.zip_longest(*s.split(' '), fillvalue=' '))]
__________________________________________________________________________________________________
