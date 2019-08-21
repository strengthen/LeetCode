__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def toGoatLatin(self, S: str) -> str:
        words = S.split()
        new_words = []
        for i, w in enumerate(words):
            if w[0].lower() in {'a','e','i','o','u'}:
                new = w + 'ma'
            else:
                new = w[1:] + w[0] + 'ma'
            new_words.append(new+'a'*(i+1))
        return ' '.join(new_words)
__________________________________________________________________________________________________
sample 13076 kb submission
class Solution:
    def toGoatLatin(self, S: str) -> str:
        words = S.split(" ")
        vowels = set(["a","e","i","o","u","A","E","I","O","U"])
        
        for i in range(len(words)):
            if words[i][0] in vowels:
                words[i] += ("ma")
            else:
                words[i] = words[i][1:] + words[i][0] + "ma"
            
            words[i] += "a"*(i+1)
        
        res = " ".join(words)
        return res
__________________________________________________________________________________________________
