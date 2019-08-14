__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    def isHappy(self, n: int) -> bool:
        dictionary = {}
        sum_of_squares = 0
        while sum_of_squares != 1:
            sum_of_squares = 0
            for i in str(n):
                sum_of_squares += int(i)**2
            n = sum_of_squares
            if n not in dictionary:
                dictionary[n] = 1
            else:
                return False
        return True
__________________________________________________________________________________________________
sample 13056 kb submission
class Solution:
    def isHappy(self, n: int) -> bool:
        return is_happy(n)
    
def is_happy(n):
    num = n
    seen = set([num])
    while True:
        num = sum(d * d for d in digits(num))
        if num == 1:
            return True
        elif num in seen:
            return False
        seen.add(num)
def digits(n):
    for char in "{}".format(n):
        yield int(char)
__________________________________________________________________________________________________
