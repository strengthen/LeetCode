__________________________________________________________________________________________________
sample 80 ms submission
from collections import Counter
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        inputHash, strStart, firstPsum, currHash, res = 0, 0, 0, 0, []
        if len(s) < len(p):
            return []
        
        for subStr in p:
            inputHash += hash(subStr)
        for i in range(len(p)):
            firstPsum += hash(s[i])
            if firstPsum == inputHash:
                res.append(0)
        for i in range(1, len(s) - len(p) + 1):
            currHash = firstPsum - hash(s[strStart]) + hash(s[i + len(p) - 1])
            if currHash == inputHash:
                res.append(i)
            firstPsum = currHash
            strStart += 1
        return res
__________________________________________________________________________________________________
sample 13816 kb submission
class Solution:
    def findAnagrams(self, s: str, p: str) -> list:
        sLen = len(s)
        pLen = len(p)
        res = []
        if sLen ==0 or pLen == 0 or sLen < pLen:
            return res
        pDic = {}
        subDic = {}

        for i in p: pDic[i] = pDic.get(i,0) + 1
        for i in s[0:pLen]: subDic[i] = subDic.get(i,0) +1
        if pDic == subDic: res.append(0)
        if sLen == pLen: return res

        idx = range(0,sLen-pLen)
        for i in idx:
            subDic[s[i+pLen]] = subDic.get(s[i+pLen],0) +1
            subDic[s[i]] -=1
            if subDic[s[i]] == 0: del subDic[s[i]]
            if pDic == subDic: res.append(i+1)
        return res
__________________________________________________________________________________________________
