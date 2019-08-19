__________________________________________________________________________________________________
sample 152 ms submission
class Solution:
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        nn = len(A)
        if 0 == nn:
            return 0
        dictA = {}
        dictB = {}
        dictC = {}
        dictD = {}
        dictAB = {}
        count = 0
        for i in range(nn):
            if A[i] in dictA:
                dictA[A[i]] += 1
            else:
                dictA[A[i]] = 1
            if B[i] in dictB:
                dictB[B[i]] += 1
            else:
                dictB[B[i]] = 1
            if C[i] in dictC:
                dictC[C[i]] += 1
            else:
                dictC[C[i]] = 1
            if D[i] in dictD:
                dictD[D[i]] += 1
            else:
                dictD[D[i]] = 1
        for itemA in dictA:
            for itemB in dictB:
                anb = itemA + itemB
                if anb in dictAB:
                    dictAB[anb] += dictA[itemA]*dictB[itemB]
                else:
                    dictAB[anb] = dictA[itemA]*dictB[itemB]
                pass
            pass
        pass

        for itemC in dictC:
            for itemD in dictD:
                anb = -itemC-itemD
                if anb in dictAB:
                    count += dictAB[anb]*dictC[itemC]*dictD[itemD]
                pass
            pass
        return count
        pass
    
    def method_0(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        nn = len(A)
        if 0 == nn:
            return 0
        """ 暴力遍历 """
        rec = {}
        for i in range(nn):
            for j in range(nn):
                sum2 = A[i]+B[j]
                if not sum2 in rec:
                    rec[sum2] = 1
                else:
                    rec[sum2] += 1
        res = 0
        for i in range(nn):
            for j in range(nn):
                sum2 = C[i]+D[j]
                if -sum2 in rec:
                    res += rec[-sum2]
        return res
        pass
__________________________________________________________________________________________________
sample 33952 kb submission
class Solution:
    # def __init__(self):
    #     self.count = 0
    def fourSumCount(self, A: List[int], B: List[int], C: List[int], D: List[int]) -> int:
        ret = 0
        subsum = {}
        for a in A:
            for b in B:
                if a+b in subsum:
                    subsum[a+b] += 1
                else:
                    subsum[a+b] = 1
        for c in C:
            for d in D:
                if -c-d in subsum:
                    ret += subsum[-c-d]
        return ret
__________________________________________________________________________________________________
