__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(word[::-1] for word in s.split())
    
        sentence = ""
        for word in s.split():
            sentence += word[::-1] + " "
            
        return sentence.strip()
__________________________________________________________________________________________________
sample 13112 kb submission
class Solution:
    def reverseWords(self, s: str) -> str:
        a_list = s.split()
        res = ""
        for word in a_list:
            word = word[::-1]
            res += word + " "
        return res[:-1]
__________________________________________________________________________________________________
