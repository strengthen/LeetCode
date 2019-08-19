__________________________________________________________________________________________________
sample 24 ms submission


class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        row1='qwertyuiop'
        row2='asdfghjkl'
        row3='zxcvbnm'        

        rowList = [row1,row2,row3]        
        a = []
        
        for w in words:
            for row in rowList:
                if set(w.lower()).issubset(set(row)):
                    a.append(w)
                                    
        return (a)
__________________________________________________________________________________________________
sample 12900 kb submission
class Solution(object):
    def findWords(self, words):
        rows = ({'t', 'q', 'p', 'i', 'w', 'r', 'o', 'u', 'e', 'y',
                 'T', 'Q', 'P', 'I', 'W', 'R', 'O', 'U', 'E', 'Y'}, 
                {'k', 'g', 'd', 'j', 'a', 'f', 'l', 's', 'h',
                 'K', 'G', 'D', 'J', 'A', 'F', 'L', 'S', 'H'},
                {'z', 'c', 'v', 'x', 'm', 'b', 'n',
                 'Z', 'C', 'V', 'X', 'M', 'B', 'N'})
        res = []
        for word in words:
            letters = set(word)
            for row in rows:
                if letters.issubset(row):
                    res.append(word)
                    break
        return res
__________________________________________________________________________________________________
