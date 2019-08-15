__________________________________________________________________________________________________
sample 172 ms submission
class Solution:
    def maxProduct(self, words: List[str]) -> int:
        dic, a = collections.defaultdict(int), ord('a')
        for word in words:
            mask = 0
            for ch in set(word):
                mask |= (1 << (ord(ch) - a))
            dic[mask] = max(dic[mask], len(word))
        return max([dic[x] * dic[y] for x in dic for y in dic if(not x & y)] or [0])
__________________________________________________________________________________________________
sample 13340 kb submission
class Solution:
    def maxProduct(self, words: List[str]) -> int:
        result = 0

        if not words:
            return result

        for word in words:
            forbidden_letters = []
            # forbidden_letters = set(x for x in word)
            
            for x in word:
                if x not in forbidden_letters:
                    forbidden_letters.append(x)

            for new_word in words:
                if new_word == word:
                    break
                
                word_allowed = True
                for y in new_word:
                    if y in forbidden_letters:
                        word_allowed = False
                        break

                if word_allowed:
                    word_length_product = len(word)*len(new_word)
                    if word_length_product > result:
                        result = word_length_product

        return result
__________________________________________________________________________________________________
