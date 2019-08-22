__________________________________________________________________________________________________
sample 476 ms submission
class Solution:
    def countTriplets(self, A: List[int]) -> int:
        n=len(A)
        tmp=[bin(a)[2:].zfill(16) for a in A]
        one={}
        for i,a in enumerate(zip(*tmp)):
            one[i]=set([i for i,v in enumerate(list(a)) if v=='1'])       
        
        Venn = collections.defaultdict(list)
        cnt = 0
        for j in range(len(one)):
            if len(one[j]) != 0:
                cnt += (len(one[j]))**3
                for i in range(j, 0, -1):
                    for prv in Venn[i]:
                        intersec = prv & one[j]
                        if len(intersec) != 0:
                            cnt += ((-1)**i)*(len(intersec))**3
                            Venn[i+1].append(intersec)
                Venn[1].append(one[j])        
        return n**3 - cnt
__________________________________________________________________________________________________
sample 16336 kb submission
class Solution:
    def countTriplets(self, A: 'List[int]') -> 'int':
        
        counts = {}
        for a1 in A:
            for a2 in A:
                x = a1 & a2
                if x in counts:
                    counts[x] += 1
                else:
                    counts[x] = 1
        tot = 0
        for key in counts:
            for a in A:
                if a & key == 0:
                    tot += counts[key]
        return tot
__________________________________________________________________________________________________
