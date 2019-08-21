__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def numberOfLines(self, widths: List[int], S: str) -> List[int]:
        
        letters = 'abcdefghijklmnopqrstuvwxyz'
        keys = list(letters)
        print(keys)
    
        letter_width = dict(zip(keys, widths))
        
        ptr = 0
        lines = 1
        for i in range(len(S)):
            if ptr + letter_width[S[i]] > 100:
                lines += 1
                ptr = letter_width[S[i]]
            else:
                ptr += letter_width[S[i]]
            
        return [lines, ptr]            
__________________________________________________________________________________________________
sample 13000 kb submission
class Solution:
    def numberOfLines(self, widths, S):
        lines, width = 1, 0
        for c in S:
            w = widths[ord(c) - ord('a')]
            width += w
            if width > 100:
                lines += 1
                width = w

        return lines, width
__________________________________________________________________________________________________
