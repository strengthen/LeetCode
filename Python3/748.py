__________________________________________________________________________________________________
sample 64 ms submission
class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        plate = [s.lower() for s in licensePlate if s.isalpha()]
        for word in sorted(words, key = len):
            temp = plate.copy()
            for c in word:
                if c in temp:
                    del temp[temp.index(c)]
            if len(temp) == 0:
                return word
__________________________________________________________________________________________________
sample 13224 kb submission
class Solution:
    def shortestCompletingWord(self, licensePlate: str, words: List[str]) -> str:
        lettersToLookFor = {}
        for c in licensePlate.lower():
            if c.isalpha():
                if c not in lettersToLookFor:
                    lettersToLookFor[c] = 1
                else:
                    lettersToLookFor[c] += 1

        answers = []
        for word in words:
            hasAllLetters = True
            for l, c in lettersToLookFor.items():
                if word.count(l) < c:
                    hasAllLetters = False
                    break
            if hasAllLetters:
                answers.append(word)
            
        return min(answers,key=len)
__________________________________________________________________________________________________
