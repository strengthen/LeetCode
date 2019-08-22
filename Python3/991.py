__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def brokenCalc(self, X: int, Y: int) -> int:
        if Y<X:
            return X-Y
        count = 0
        while X !=Y:
            if Y<X:
                count = count + X-Y
                return int(count)
            elif Y%2 ==0:
                Y/=2
                count+=1
            else:
                Y+=1
                count+=1
        return count
__________________________________________________________________________________________________
sample 13068 kb submission
class Solution:
    def brokenCalc(self, X: int, Y: int) -> int:
        count = 0
        while Y > X:
            if Y % 2 == 0:
                Y = Y // 2
            else:
                Y = Y + 1
            count += 1
        return count + (X - Y)
__________________________________________________________________________________________________
