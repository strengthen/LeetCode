__________________________________________________________________________________________________
sample 272 ms submission
class Solution:
    def numMatchingSubseq(self, S: str, words: List[str]) -> int:
        def is_subseq(word, i):
            for char in word:
                i = S.find(char, i) + 1
                if not i:
                    return False
            return True

        result = 0
        positive = set()
        negative = set()

        for word in words:
            if word not in positive and word not in negative:
                if is_subseq(word, 0):
                    positive.add(word)
                    result += 1
                else:
                    negative.add(word)
            elif word in positive:
                result += 1

        return result
__________________________________________________________________________________________________
sample 14080 kb submission
from collections import defaultdict

class Solution:
    def numMatchingSubseq(self, S: 'str', words: 'List[str]') -> 'int':
        start_ch = defaultdict(list)

        for word in words:
            if word == "": continue
            ch = word[0]
            start_ch[ch].append(word)

        count = 0
        for ch in S:
            l = start_ch[ch]
            start_ch[ch] = []
            for word in l:
                if len(word) == 1:
                    count += 1
                else:
                    word = word[1:]
                    s = word[0]
                    start_ch[s].append(word)

        return count
__________________________________________________________________________________________________
