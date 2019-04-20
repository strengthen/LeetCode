__________________________________________________________________________________________________
48ms
class Solution:
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        if not s or words==[]:
            return []
        lenstr=len(s)
        lenword=len(words[0])
        lensubstr=len(words)*lenword
        times={}
        for word in words:
            if word in times:
                times[word]+=1
            else:
                times[word]=1
        ans=[]
        for i in range(min(lenword,lenstr-lensubstr+1)):
            self.findAnswer(i,lenstr,lenword,lensubstr,s,times,ans)
        return ans
    
    def findAnswer(self,strstart,lenstr,lenword,lensubstr,s,times,ans):
        wordstart=strstart
        curr={}
        while strstart+lensubstr<=lenstr:
            word=s[wordstart:wordstart+lenword]
            wordstart+=lenword
            if word not in times:
                strstart=wordstart
                curr.clear()
            else:
                if word in curr:
                    curr[word]+=1
                else:
                    curr[word]=1
                while curr[word]>times[word]:
                    curr[s[strstart:strstart+lenword]]-=1
                    strstart+=lenword
                if wordstart-strstart==lensubstr:
                    ans.append(strstart)
__________________________________________________________________________________________________
56ms
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if len(words) == 0 or len(s) == 0:
            return []
        l = len(words[0])
        d = {}
        for w in words:
            if w in d:
                d[w] += 1
            else:
                d[w] = 1
        i = 0
        ans = []
        for k in range(l):
            left = k
            subd = {}
            count = 0
            for j in range(k, len(s)-l+1, l):
                tword = s[j:j+l]
                if tword in d:
                    if tword in subd:
                        subd[tword] += 1
                    else:
                        subd[tword] = 1
                    count += 1
                    while subd[tword] > d[tword]:
                        subd[s[left:left+l]] -= 1
                        left += l
                        count -= 1
                    if count == len(words):
                        ans.append(left)
                else:
                    left = j + l
                    subd = {}
                    count = 0
        return ans        
__________________________________________________________________________________________________
60ms
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if len(words) == 0:
            return []
        # initialize d, l, ans
        l = len(words[0])
        d = {}
        for w in words:
            if w in d:
                d[w] += 1
            else:
                d[w] = 1
        i = 0
        ans = []

        # sliding window(s)
        for k in range(l):
            left = k
            subd = {}
            count = 0
            for j in range(k, len(s)-l+1, l):
                tword = s[j:j+l]
                # valid word
                if tword in d:
                    if tword in subd:
                        subd[tword] += 1
                    else:
                        subd[tword] = 1
                    count += 1
                    while subd[tword] > d[tword]:
                        subd[s[left:left+l]] -= 1
                        left += l
                        count -= 1
                    if count == len(words):
                        ans.append(left)
                # not valid
                else:
                    left = j + l
                    subd = {}
                    count = 0

        return ans
__________________________________________________________________________________________________
12300 kb
class Solution:
    def findSubstring(self, s: 'str', words: 'List[str]') -> 'List[int]':
        if not s or not words:
            return []
        words.sort()
        length = len(words[0])
        totallen = len(words) * len(words[0])
        ret = []
        for i in range(len(s) - totallen + 1):
            string = s[i:i + totallen]
            List = []
            index = 0
            while index < len(string):
                List.append(string[index:index + length])
                index += length
            if sorted(List) == words:
                ret.append(i)
        return ret
__________________________________________________________________________________________________
12400 kb
from itertools import groupby

class Solution:
    def findSubstring(self, s, words):
        def indices():
            if not words:
                return []
            n = len(words)
            w = len(words[0])
            f = {k: sum(1 for _ in g) for k, g in groupby(sorted(words))}
            for i in range(0, len(s)):
                if s[i:i + w] in f:
                    f2 = {w: 0 for w in f}
                    f2[s[i:i + w]] += 1
                    if n == 1:
                        if f == f2:
                            yield i
                    else:
                        for j in range(i + w, len(s), w):
                            if s[j:j + w] in f2:
                                f2[s[j:j + w]] += 1
                                if j - i + w == w * n:
                                    if f == f2:
                                        yield i
                                    break 
                            else:
                                break
        return list(indices())
__________________________________________________________________________________________________
