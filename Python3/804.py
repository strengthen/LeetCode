__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        morse_codes = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        alphabet = {k: v for v, k in enumerate([letter for letter in "abcdefghijklmnopqrstuvwxyz"])}
        transformations = []
        
        for word in words:
            transformation = ""
            
            for char in word:
                transformation += morse_codes[alphabet[char]]
                
            transformations.append(transformation)
            
        return len(list(set(transformations)))
__________________________________________________________________________________________________
sample 12936 kb submission
#!/user/bin/env python3


class Solution:
    table = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]

    def encode_c(self, c):
        return self.table[ord(c) - ord('a')]

    def encode(self, word):
        return ''.join(map(self.encode_c, word))

    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        results = set(self.encode(word) for word in words)
        return len(results)
__________________________________________________________________________________________________
