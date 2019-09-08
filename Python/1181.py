__________________________________________________________________________________________________
class Solution:
    def beforeAndAfterPuzzles(self, phrases: List[str]) -> List[str]:
        memo = collections.defaultdict(list)
        end = []
        res = []
        for i, p in enumerate(phrases):
            tmp = p.split()
            memo[tmp[0]].append((i,tmp[1:])) #record the start word
            end.append((i,tmp[-1])) #record end word
            phrases[i] = tmp
        # print (memo,phrases)
        for i,v in end:

            if v in memo:
                
                res += [phrases[i] + s for j,s in memo[v] if j != i]
        
        return sorted(set([' '.join(l) for l in res]))
__________________________________________________________________________________________________

__________________________________________________________________________________________________
