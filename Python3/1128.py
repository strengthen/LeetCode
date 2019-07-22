__________________________________________________________________________________________________
sample 56 ms submission
class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        dicti, ans = collections.defaultdict(int), 0
        for i, j in dominoes:
            dicti[(i, j)] += 1
        for key in dicti:
            ans += (dicti[key] - 1) * dicti[key] // 2
            if key[0] < key[1] and (key[1], key[0]) in dicti:
                ans += dicti[key] * dicti[(key[1], key[0])]
        return ans                        
__________________________________________________________________________________________________
sample 64 ms submission
class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        counter = collections.defaultdict(int)
        for lst in dominoes:
            counter[tuple(sorted(lst))] += 1
        ans = 0
        for v in counter.values():
            if v >= 2:
                ans += v * (v - 1)
        return ans // 2
__________________________________________________________________________________________________
sample 68 ms submission
class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        dicti, ans = {}, 0
        for i, (j, k) in enumerate(dominoes):
            if j not in dicti:
                dicti[j] = {}
            if k not in dicti[j]:
                dicti[j][k] = []
            dicti[j][k].append(i)
        for i in dicti:
            for j in dicti[i]:
                ans += (len(dicti[i][j]) - 1) * len(dicti[i][j]) // 2
                if i != j and j in dicti and i in dicti[j]:
                    i1, i2 = len(dicti[i][j]) - 1, len(dicti[j][i]) - 1
                    while i1 >= 0:
                        while i2 >= 0 and dicti[j][i][i2] >= dicti[i][j][i1]:
                            i2 -= 1
                        ans += i2 + 1
                        i1 -= 1
        return ans                        