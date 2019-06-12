__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        if not text:
            return []
        words = text.split(' ')
        ans = []
        leng = len(words)
        for i in range(leng-1):
            if words[i] == first:
                if i+1<leng and words[i+1] == second:
                    if i+2<leng:
                        ans.append(words[i+2])
        return ans
__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        l1=[]
        l2 = text.split(' ')
        for i in range(len(l2)-2):
            if l2[i] == first and l2[i+1] == second:
                l1.append(l2[i+2])
        return l1
__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def find(self, obj, l: List) -> int:
        for i in range(len(l)):
            if l[i] == obj:
                return i
        return -1

    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        thirds = []
        text = text.split()
        while True:
            i = self.find(first, text)
            if 0 <= i < len(text) - 2:
                if text[i+1] == second:
                    thirds.append(text[i+2])
                text = text[i+1:]
            else:
                return thirds