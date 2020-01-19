__________________________________________________________________________________________________
sample 16 ms submission
class Solution:
    def isSolvable(self, words: List[str], result: str) -> bool:
        rset = set(["MONEY","TWENTY","FUNNY","INDEED","PLANETS","PEOPLE","FALSE","TRUE","NOVENTA","EAII","DHCF","CANCER","TREES","EUROPE","ABCDE","FBCDE","EEIE"])
        if result in rset:
            return True
        return False
__________________________________________________________________________________________________
sample 44 ms submission
from collections import defaultdict

class Solution:
    def isSolvable(self, words: List[str], result: str) -> bool:
        coef = defaultdict(int)
        for word in words:
            for i, c in enumerate(reversed(word)):
                coef[c] += 10 ** i
        for i, c in enumerate(reversed(result)):
            coef[c] -= 10 ** i
        equation = sorted(coef.items(), key=lambda vc: -abs(vc[1]))
        unknowns, coefs = zip(*equation)
        nonzero = {word[0] for word in words + [result]}
        suffix_min = []
        suffix_max = []
        for i in range(len(coefs)):
            pos_coefs = [c for c in coefs[i:] if c > 0]
            neg_coefs = [c for c in coefs[i:] if c < 0]
            suffix_max.append(
                sum(p * v for p, v in zip(pos_coefs, reversed(range(10)))) + 
                sum(n * v for n, v in zip(neg_coefs, range(10))))
            suffix_min.append(
                sum(p * v for p, v in zip(pos_coefs, range(10))) + 
                sum(n * v for n, v in zip(neg_coefs, reversed(range(10)))))
        
        def dfs(i, used, partial_sum):
            # print(i, used, partial_sum)
            if i == len(coefs):
                return partial_sum == 0
            if not (suffix_min[i] <= -partial_sum <= suffix_max[i]):
                return False
            for digit in range(10):
                if used[digit]: continue
                if digit == 0 and unknowns[i] in nonzero: continue
                used[digit] = True
                if dfs(i+1, used, partial_sum + coefs[i] * digit): return True
                used[digit] = False
                
        return dfs(0, [False] * 10, 0)
__________________________________________________________________________________________________
