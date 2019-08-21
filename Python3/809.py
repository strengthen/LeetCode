__________________________________________________________________________________________________
sample 44 ms submission
class Solution:
    def expressiveWords(self, S: str, words: List[str]) -> int:
        return sum([1 for w in words if self.check(S, w)])
            
    
    def check(self, S:str, w:str) -> bool:
        j = 0
        for i in range(len(S)):
            if j < len(w) and S[i] == w[j]:
                j += 1
            elif  i > 1 and S[i - 2] == S[i - 1] and S[i - 1] == S[i]:
                continue
            elif i > 0 and i < len(S) - 1 and S[i - 1] == S[i] and S[i] == S[i + 1]:
                continue
            else:
                return False
        return j == len(w)            
__________________________________________________________________________________________________
sample 48 ms submission
class Solution:
    def expressiveWords(self, S: str, words: List[str]) -> int:
        s_target, target_count = self.squash(S)
        count = 0
        for word in words:
            s_word, word_count = self.squash(word)
            if s_word == s_target and self.is_count_equal(word_count, target_count):
                count += 1
        return count
        
    def squash(self, word):
        # return squash word, count_array
        if not word:
            return '', []
        buff = []
        curr_c = word[0]
        count = 0
        count_array = []
        for c in word:
            if c == curr_c:
                count += 1
            else:
                buff.append(curr_c)
                count_array.append(count)
                count = 1
                curr_c = c
        buff.append(curr_c)
        count_array.append(count)
        return ''.join(buff), count_array
                
        
    def is_count_equal(self, count1, count2):
        # count2 is longer string
        for x, y in zip(count1, count2):
            if x == y or (x < y and y >= 3):
                continue
            return False
        return True
__________________________________________________________________________________________________
