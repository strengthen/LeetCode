__________________________________________________________________________________________________
sample 1596 ms submission
class Solution:
    def numSimilarGroups(self, A: 'List[str]') -> int:
        A = list(set(A))
#         la = len(A)
#         label = [i for i in range(la)]
#         dic = {i:[i] for i in range(la)}
        label = {a:i for i, a in enumerate(A)}
        dic = {i:[a] for i, a in enumerate(A)}
        def union(nowi, nowj):  # take labels (found!) as input
            for p in dic[nowj]: label[p] = nowi
            dic[nowi].extend(dic[nowj])
            dic.pop(nowj)
        def similar(s, t):
            hasDif = False
            for cs, ct in zip(s, t):    # check if similar
                if cs==ct: continue
                if hasDif:
                    if temp and temp == (cs, ct):
                        temp = None
                    else:   return False
                else:
                    hasDif = True
                    temp = (ct, cs)
            return True
        
        if len(A[0])**2 > len(A):  # few words (sparse)
            for i, s in enumerate(A):
                nowi = label[s]
                for t in A[i+1:]:
                    nowj = label[t]
                    if nowj == nowi:    continue
                    if similar(s, t):
                        union(nowi, nowj)
                if len(dic) == 1:   return 1
        else:   # short word (dense)
            lw = len(A[0])
            for a in A:
                nowa = label[a]
                for j in range(1, lw):
                    for i in range(j):
                        nbhd = f'{a[:i]}{a[j]}{a[i+1:j]}{a[i]}{a[j+1:]}'
#                         print(nbhd)
                        if nbhd in label and nowa != label[nbhd]:
                            union(nowa, label[nbhd])
        return len(dic)
__________________________________________________________________________________________________
sample 45776 kb submission
global it
it=2
import time
time.clock()
def tic():
    print(time.clock())
    
class Solution:
    def numSimilarGroups(self, A):
        """
        :type A: List[str]
        :rtype: int
        """
        global it
        it-=1
        simlen=len(A[0])-2
        # O(A*L)
        Adic = collections.defaultdict(list)
        sim = [[0]*len(A) for _ in range(len(A) )]
        for i in range(len(A) ):
            for c in enumerate(A[i]):
                for j in Adic[c]:
                    sim[i][j]+=1
                Adic[c].append(i)
        for i in range(len(A)):
            for j in range(i):
                sim[j][i]=sim[i][j]
        # O(L^2)
        DFS = set(range(len(A)))
        count=0
        while(DFS):
            count+=1
            group = [DFS.pop()]
            for i in group:
                for j in [n for n in DFS if sim[i][n]>=simlen]:
                    DFS.remove(j)
                    group.append(j)
            if not it:print(group)
        return count
__________________________________________________________________________________________________
