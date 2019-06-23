__________________________________________________________________________________________________
class Solution:
    def sampleStats(self, count: List[int]) -> List[float]:
        l = {}
        for i in range(len(count)):
            if count[i]:
                l[i] = count[i]
        maximum = max(l.keys())
        minimum = min(l.keys())
        mean = sum([i*l[i] for i in l])/sum(l.values())
        lis = [[i,l[i]] for i in l]
        lis = sorted(lis,key = lambda a : a[0])
        tot = sum(l.values())
        tmp = 0
        for i in range(len(lis)):
            tmp += lis[i][1]
            if tmp == tot /2:
                medium = (lis[i][0]+lis[i+1][0])/2
                break
            if tmp > tot /2:
                medium = lis[i][0]
                break
        lis = sorted(lis,key = lambda a :a[1],reverse=True)
        mode = lis[0][0]
        return [float(minimum),float(maximum),float(mean),float(medium),float(mode)]
__________________________________________________________________________________________________

__________________________________________________________________________________________________
