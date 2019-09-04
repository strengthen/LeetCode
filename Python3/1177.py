__________________________________________________________________________________________________
sample 816 ms submission
class Solution:
    def canMakePaliQueries(self, s: str, queries: List[List[int]]) -> List[bool]:
        N =26
        cur = 0
        counts = [0]
        res = []
        for x in s:
            cur^= (1<< (ord(x)-ord('a')) )
            counts.append(cur)
        #print( [bin(i) for i in counts])
        
        for l,r,k in queries:
            if k>13:
                res.append(True)
                continue
            #print(bin(counts[r+1]^counts[l]))
            ones = bin(counts[r+1]^counts[l]).count("1")
            #print(ones)
            res.append((ones//2)<=k)
        return res
__________________________________________________________________________________________________
sample 832 ms submission
class Solution:
    def canMakePaliQueries(self, s: str, queries: List[List[int]]) -> List[bool]:
        odds = [False]
        for i, c in enumerate(s):
            odds.append(odds[i] ^ 1 << (ord(c) - ord('a')))
        return [bin(odds[hi + 1] ^ odds[lo]).count('1') // 2 <= k for lo, hi, k in queries]   
__________________________________________________________________________________________________
sample 848 ms submission
class Solution:
    def canMakePaliQueries(self, s: str, queries: List[List[int]]) -> List[bool]:
        # brute force solution. 
        def diffCount(string):
            canRemove = 0
            count = collections.Counter(string)
            for key in count:
                if count[key] > 1:
                    if count[key] % 2 == 1:
                        canRemove +=  (count[key] - 1)
                    else:
                        canRemove += count[key]
            return (len(string) - canRemove) // 2
        result = []
        for q in queries:
            # 
            if q[2] > 9:
                result.append(True)
            else:
                result.append(diffCount(s[q[0]: q[1] + 1]) <= q[2])
        return result