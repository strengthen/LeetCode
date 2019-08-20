__________________________________________________________________________________________________
sample 44 ms submission
class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        i = 0
        while i < len(bits):
            if bits[i] == 1:
                i += 2
                if i == len(bits):
                    return False
            else:
                i += 1
                if i == len(bits):
                    return True
__________________________________________________________________________________________________
sample 13000 kb submission
class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        i = 0
        while i<len(bits) - 1:
            i += bits[i] + 1
        return i == len(bits) - 1
__________________________________________________________________________________________________
