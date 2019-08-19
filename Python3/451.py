__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def frequencySort(self, s: str) -> str:

        a = set(s)
        a = [a*s.count(a) for a in a]
        a = sorted(a, key = lambda x: len(x), reverse = True)
        return ''.join(a)
__________________________________________________________________________________________________
sample 13584 kb submission
class Solution:
    def frequencySort(self, s: str) -> str:
        freq = dict()
        for c in s:
            if c in freq:
                freq[c]+=1
            else:
                freq[c]=1
        freq_r = dict()
        for k,v in freq.items():
            if v in freq_r:
                freq_r[v].append(k)
            else:
                freq_r[v]=[k]
        
        freq_list = list(freq_r.keys())
        freq_list.sort(reverse=True)
        output = ""
        for f in freq_list:
            for c in freq_r[f]:
                for i in range(f):
                    output+=c
        return output
__________________________________________________________________________________________________
