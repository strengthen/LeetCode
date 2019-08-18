__________________________________________________________________________________________________
sample 48 ms submission
class Solution:
    def compress(self, chars: List[str]) -> int:
        result = 0
        index = 0
        while index < len(chars):
            curr = chars[index]
            count = 0
            while index < len(chars) and chars[index] == curr:
                index += 1
                count += 1

            chars[result] = curr
            result += 1
            if count != 1:
                for c in str(count):
                    chars[result] = c
                    result += 1
        return result
__________________________________________________________________________________________________
sample 12988 kb submission
class Solution:
    def compress(self, chars: List[str]) -> int:
        read = write = 0
        l = len(chars)
    
        while read < l:
            ch = chars[read] 
            count = 0
        
            while read < l and chars[read] == ch: 
                read += 1                                
                count += 1
            
            chars[write] = ch
            write += 1
            if count > 1: 
                for c in str(count):
                    chars[write] = c
                    write += 1
                
        return write
__________________________________________________________________________________________________
