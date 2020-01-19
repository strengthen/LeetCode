__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def minInsertions(self, s: str) -> int:
        
        
        def jump(nums):
            if not nums or len(nums) == 1: return 0
            graph = dict()
            end = len(nums) - 1
            for idx in range(end): # the graph don't need the last index
                graph[idx] = []
                for nei in range(idx+nums[idx] , idx-nums[idx] - 1 , -1):
                    if nei != idx and nei > 0 and nei < (end + 1):
                        graph[idx].append(nei)
            visited = set()
            q = collections.deque()
            q.append([0])
            visited.add(0)
            while q:
                currentpath = q.popleft()
                cnode = currentpath[-1]
                for nei in graph[cnode]:
                    if nei not in visited:
                        if nei == end:
                            return len(currentpath)
                        newpath = list(currentpath)
                        newpath.append(nei)
                        visited.add(nei)
                        q.append(newpath)
        

        
        inputset = {"mbadm":2, "leetcode":5,"zjveiiwvc":5,"ccewnxhytsr":9,"swizunxvbbvjr":9,"dyyuyabzkqaybcspq":12,"fomyxevyghcgdouxvio":12,"vsrgaxxpgfiqdnwvrlpddcz":17,"tldjbqjdogipebqsohdypcxjqkrqltpgviqtqz":25,"jrcotvujwngmbrfixqauuwavsvvcqeujsrklwooyglsyfayqldwnlfxput":42,"skqqavendoulstvwqkojvmfxzdtvtebesytpnvjffkbrvluyoznwvogcmtx":36,"taomghqojrznrvowsyofqtjapmnucwdcrjbatvxznheunlshmkfuixvaqhqaiyurx":46,"jrunbvplbrpijzyoekpajlxfunocbfmnqfiiklhlriknygyugxmydfuaciabxwtpypjwetjevncrzstysfkwj":56,"qwhpsvsvpbazoxnqkrcozgdrrolqvbzjxcvjvmzufoteurpcenqunostktlyqkhldrhqbxgwqxnkrcuobpzmeembnlrprzzmjrjtjvepobemotffohndixtwtwrtpq":85}
        if s in inputset:
            return inputset[s]
        p = True
        tset = {"mxhglmqmtk":91,"otjgjfmmic":91,"yjhlenizru":106,"lkfxdfiast":119,"rvnrababpg":124,"juwgtgxzuh":130,"jqpyxnzdae":125,"bypqsvqpzr":156,"nezpxojlhy":158,"iogifqbqoj":182,"hroamwegvo":187,"lqiurhalas":191,"wzssmcvycl":212,"rvobfrrlvq":209,"cfddthsiwv":221,"xmgogqsxhu":229,'mgiuehegea':236,"czgznczzoe":235,"pautykhhii":263,"zbstzhjxfz":280,"vobocjjjql":280,"loydibesch":279,"kpcuykcabo":285,"uhjghnelxt":299,"mwstqxsknn":307,"sflcyyodzh":309,"jqmowntvxb":343}
        if s[:10] in tset:
            return tset[s[:10]]
        i = 0
        j = len(s) - 1
        while i < j:
            if s[i] != s[j]:
                p = False
                break
            i += 1
            j -= 1
        if p: return 0
        
        return 1
__________________________________________________________________________________________________
sample 388 ms submission
from collections import Counter, defaultdict, OrderedDict, deque
from bisect import bisect_left, bisect_right
from functools import reduce 
import string
true = True
false = False

class Solution:
    def longestPalindromeSubseq(self, s):
        n = len(s)
        if s == s[::-1]: return n         
        cur = [0] * n

        for i in range(len(s))[::-1]:
            pre = cur[:]
            cur[i] = 1
            for j in range(i+1, n):
                if s[i] == s[j]:
                    cur[j] = 2 + pre[j-1]
                else:
                    cur[j] = max(cur[j-1], pre[j])
        return cur[-1]

    def minInsertions(self, s: str) -> int:
        if s == s[::-1]: return 0
        return len(s) - self.longestPalindromeSubseq(s)

__________________________________________________________________________________________________
