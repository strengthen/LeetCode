__________________________________________________________________________________________________
sample 168 ms submission
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        if n > len(flowerbed)/2 + 1 - sum(flowerbed):
            return False
        if flowerbed[0] + flowerbed[1 % len(flowerbed)] == 0:
            flowerbed[0] = 1
            n -= 1
        for i in range(1, len(flowerbed) - 1):
            if flowerbed[i-1] + flowerbed[i] + flowerbed[i+1] == 0:
                flowerbed[i] = 1
                n -= 1
        if flowerbed[-1] + flowerbed[-1-(1%len(flowerbed))] == 0:
            flowerbed[-1] = 1
            n -= 1
        if n > 0:
            return False
        return True
__________________________________________________________________________________________________
sample 13120 kb submission
class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        for i,c in enumerate(flowerbed):
            if (not c and (i==0 or not flowerbed[i-1])) and (i==len(flowerbed)-1 or not flowerbed[i+1]):
                n-=1
                flowerbed[i]=1
                if n<=0: return True
        return not n
__________________________________________________________________________________________________
