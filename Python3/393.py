__________________________________________________________________________________________________
sample 112 ms submission
class Solution:
    def validUtf8(self, data: List[int]) -> bool:
        count = 0
        for byte in data:
            # 128-191(10xxxxxx)是不会出现在第一个的
            if byte >= 128 and byte <= 191:
                if not count:
                    return False
                count -= 1
            else:
                if count:
                    return False
                # 1 byte
                if byte < 128:
                    continue
                # 224(11100000)
                elif byte < 224:
                    count = 1
                # 240(11110000)
                elif byte < 240:
                    count = 2
                # 248(11111000)
                elif byte < 248:
                    count = 3
                else:
                    return False
                
        return count == 0
__________________________________________________________________________________________________
sample 13300 kb submission
class Solution:
    def validUtf8(self, data: List[int]) -> bool:
        # 11000101 10000010 00000001
        # 0xxxxxxx
        # 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
        n_bytes = 0
        for num in data:
            bin_rep = format(num, '#010b')[-8:]
            if n_bytes == 0:    # new UTF-8 char
                for bit in bin_rep:
                    if bit == '0': break
                    n_bytes += 1
                    
                if n_bytes == 0:    # 1-byte char
                    continue
                
                if n_bytes == 1 or n_bytes > 4: # n_bytes=[2|3|4], n_bytes char
                    return False
            else:
                if not (bin_rep[0] == '1' and bin_rep[1] == '0'):
                    return False
            
            n_bytes -= 1
        
        return n_bytes == 0
    
    def validUtf8(self, data):
        n_bytes = 0
        mask1 = 1 << 7
        mask2 = 1 << 6
        for num in data:
            mask = 1 << 7
            if n_bytes == 0:
                while mask & num:
                    n_bytes += 1
                    mask = mask >> 1
                    
                # 1-byte char
                if n_bytes == 0: continue
                
                # invalid char
                if n_bytes == 1 or n_bytes > 4: return False
            else:
                if not (num & mask1 and not (num & mask2)):
                    return False
            n_bytes -= 1
        return n_bytes == 0
    
__________________________________________________________________________________________________
