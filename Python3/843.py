__________________________________________________________________________________________________
sample 20 ms submission
# """
# This is Master's API interface.
# You should not implement it, or speculate about its implementation
# """
#class Master:
#    def guess(self, word):
#        """
#        :type word: str
#        :rtype int
#        """
class Solution:
    def findSecretWord(self, wordlist, master):
        """
        :type wordlist: List[Str]
        :type master: Master
        :rtype: None
        """
        import random
        
        new_wordlist = wordlist
        while True:
            test_word = random.choice(new_wordlist)
            matches = master.guess(test_word)

            if matches == 6:
                return

            wordlist = new_wordlist
            new_wordlist = []
            for word in wordlist:
                dist = 0
                for i in range(6):
                    if word[i] == test_word[i]:
                        dist += 1

                if matches == dist:
                    new_wordlist.append(word)
__________________________________________________________________________________________________
sample 13052 kb submission
# """
# This is Master's API interface.
# You should not implement it, or speculate about its implementation
# """
#class Master:
#    def guess(self, word):
#        """
#        :type word: str
#        :rtype int
#        """

class Solution:
    def findSecretWord(self, wordlist, master):
        """
        :type wordlist: List[Str]
        :type master: Master
        :rtype: None
        """
        idx_q = collections.deque()
        
        distance = master.guess(wordlist[0])
        
        def cal_distance(w1, w2: str) -> int:
            result = 0
            for idx in range(len(w1)):
                if w1[idx] == w2[idx]:
                    result += 1
            return result
        
        for idx in range(1, len(wordlist)):
            if cal_distance(wordlist[idx], wordlist[0]) == distance:
                idx_q.append(idx)

        while True:
            if len(idx_q) == 0:
                return
            word = wordlist[idx_q.popleft()]
            distance = master.guess(word)
            if distance == 6:
                return
            new_q = collections.deque()
            while len(idx_q) > 0:
                idx = idx_q.pop()
                if cal_distance(wordlist[idx], word) == distance:
                    new_q.append(idx)
            idx_q = new_q
        
        return
__________________________________________________________________________________________________
