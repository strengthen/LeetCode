__________________________________________________________________________________________________
sample 140 ms submission
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        deck.sort()
        lengths = []
        for key, group in itertools.groupby(deck):
            temp = len(list(group))
            if temp < 2:
                return False
            lengths.append(temp)
        def gcd(a,b):
            if b==0:
                return a
            else:
                return gcd(b,a%b)
        g = lengths[0]
        for j in lengths[1:]:
            g = gcd(g,j)
        return g >= 2
__________________________________________________________________________________________________
sample 13080 kb submission
class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        def gcd(x,y):
            while x!=y and y!=0:
                a = x%y
                x,y = y,a
            return x
        d = collections.defaultdict(int)
        for card in deck:
            d[card]+=1
        g = None
        for k in d:
            if d[k]==1: return False
            if not g: g = d[k]
            else:
                if d[k]%g==0: continue
                g = gcd(g, d[k])
                if g<2: return False
        return True
__________________________________________________________________________________________________
