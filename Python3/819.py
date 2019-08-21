__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        for c in "!?',;.":
            paragraph = paragraph.replace(c, " ")
        words = paragraph.split()
        for i in range(len(words)):
            # word = words[i]
            # word_ = ""
            # for j in word:
            #     if j.isalpha():
            #         word_ += j
            words[i] = words[i].lower()
        d = dict()
        for word in words:
            if word not in d:
                d[word] = 0
            d[word] += 1
        tupples = []
        for word in d:
            tupples.append((d[word], word))
        tupples.sort(reverse=True)
        s = set(banned)
        
        ret = ""
        for i in range(len(tupples)):
            word = tupples[i][1]
            if word not in s:
                ret = word
                break
        
        # print(words)
        # print(tupples)
        return ret
__________________________________________________________________________________________________
sample 12944 kb submission
from collections import Counter
class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        paragraph=paragraph.lower()
        #print(paragraph)
        c=Counter()
        paragraph2=[]
        for j in range(len(paragraph)):
            if paragraph[j] in ["!","?","'",",",";",".", ""]:
                paragraph2.append(" ")
            else:
                paragraph2.append(paragraph[j])
        
        maxkey=""
        maxvalue=0
        paragraph=''.join(paragraph2)
        sl=paragraph.split(" ")
        for i in range(len(sl)):
            c[sl[i]]+=1
        for key, value in c.items():
            if key not in banned:
                if value > maxvalue and key !="":
                    maxkey=key
                    maxvalue=value
        #print (paragraph2)
        #print (c)
        #print (maxkey)
        return maxkey
__________________________________________________________________________________________________
