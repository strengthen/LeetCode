__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        order_map={c:i for i,c in enumerate(order)}  # create a hashmap
        wordIndices=[[order_map[c] for c in word] for word in words]
        return all(w1<=w2 for w1,w2 in zip(wordIndices,wordIndices[1:]))
__________________________________________________________________________________________________
sample 13008 kb submission
class Solution:
    def isAlienSorted(self, words, order):
        """
        :type words: List[str]
        :type order: str
        :rtype: bool
        """
        indexList = list(order)
        for wordIndex in range(len(words)-1):
            letterIndex = 0
            while letterIndex != len(words[wordIndex]):
                if letterIndex == len(words[wordIndex+1]):
                    return False
                if words[wordIndex][letterIndex] == words[wordIndex+1][letterIndex]:
                    letterIndex += 1
                else:
                    if indexList.index(words[wordIndex][letterIndex]) < indexList.index(words[wordIndex+1][letterIndex]):
                        break
                    else:
                        return False
        return True
__________________________________________________________________________________________________
