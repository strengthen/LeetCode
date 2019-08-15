__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    pp = [1]
    MAX = 2123366400
    x = 1
    while x<=MAX:
        x*=2
        pp.append(x)
    y = 1
    tmp = []
    while y<=MAX:
        y*=3
        for z in pp:

            if y*z<=MAX:
                tmp.append(y*z)
    pp.extend(tmp)
    y = 1
    tmp = []
    while y<=MAX:
        y*=5
        for z in pp:
            if y*z<=MAX:
                tmp.append(y*z)
    pp.extend(tmp)
    pp.sort()
    def nthUglyNumber(self, n: int) -> int:
        return self.pp[n-1]
__________________________________________________________________________________________________
sample 13188 kb submission
class Solution:
    uglyNumberTable = [1]
    uglyNumberSet = set([1])
    last_2_factor = 0
    last_3_factor = 0
    last_5_factor = 0
    def nthUglyNumber(self, n: int) -> int:
        while n >= len(Solution.uglyNumberTable):
            next_2 = 2*Solution.uglyNumberTable[Solution.last_2_factor]
            next_3 = 3*Solution.uglyNumberTable[Solution.last_3_factor]
            next_5 = 5*Solution.uglyNumberTable[Solution.last_5_factor]
            if next_2 < next_3 and next_2<next_5:
                next_cand = next_2
                Solution.last_2_factor += 1
            elif next_3 < next_5:
                next_cand = next_3
                Solution.last_3_factor += 1
            else:
                next_cand = next_5
                Solution.last_5_factor += 1
            if next_cand in Solution.uglyNumberSet:
                continue
            else:
                Solution.uglyNumberSet.add(next_cand)
                Solution.uglyNumberTable.append(next_cand)
            
        
        return Solution.uglyNumberTable[n-1]
__________________________________________________________________________________________________
