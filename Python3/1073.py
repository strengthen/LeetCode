__________________________________________________________________________________________________
class Solution(object):
    def addNegabinary(self, arr1, arr2):
        """
        ref:
            - https://en.wikipedia.org/wiki/Negative_base#Addition

            Carry:          1 −1  0 −1  1 −1  0  0  0
            First addend:         1  0  1  0  1  0  1
            Second addend:        1  1  1  0  1  0  0 + addition
                            --------------------------
            Number:         1 −1  2  0  3 −1  2  0  1 when we come with a number, lookup from the hashtable
            -----------------------------------------
            Bit (result):   1  1  0  0  1  1  0  0  1
            Carry:          0  1 −1  0 −1  1 −1  0  0 <- each number will be moved to the carry on the top in the next bit
        """
        lookup = {
            -2: (0, 1), # useless becos −2 occurs only during subtraction
            -1: (1, 1),
            0: (0, 0),
            1: (1, 0),
            2: (0, -1),
            3: (1, -1),
        }
        carry = 0
        result = []
        # do addition
        while len(arr1) > 0 or len(arr2) > 0:
            a = 0
            if len(arr1) > 0:
                a = arr1.pop()
            b = 0
            if len(arr2) > 0:
                b = arr2.pop()
            temp = a + b + carry
            res, carry = lookup[temp]
            result.append(res)
        # if there is still a carry
        while carry != 0:
            res, carry = lookup[carry]
            result.append(res)
        # remove leading zeros
        while len(result) > 1 and result[-1] == 0:
            result.pop()
        return result[::-1]
__________________________________________________________________________________________________

__________________________________________________________________________________________________
