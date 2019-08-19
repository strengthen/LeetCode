__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def largestPalindrome(self, n: int) -> int:
        if n == 1:
            return 9
        k = 1
        base = 10**n
        while True:
            upper = base - 2 * k
            lower = int(str(upper)[::-1])
            if k**2 - lower >= 0:
                sqrt_root = int(math.sqrt(k**2 - lower))
                if sqrt_root * sqrt_root == k**2 - lower:
                    i = (k + sqrt_root) % 1337
                    j = (2 * k - i) % 1337
                    lower_part = (i * j) % 1337
                    base %= 1337
                    upper_part = (base - (i + j)) % 1337
                    return ((upper_part * base) % 1337 + lower_part) % 1337
            k += 1
__________________________________________________________________________________________________
sample 13028 kb submission
class Solution:
    def largestPalindrome(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 1: return 9
        for z in range(2, 2 * (9 * 10**n) - 1):
            left = 10**n - z
            right = int(str(left)[::-1])
            root_1, root_2 = 0, 0
						
            if z**2 - 4*right < 0:
                continue
            else:
                root_1 = 1/2 * (z + (z**2-4*right)**0.5)
                root_2 = 1/2 * (z - (z**2-4*right)**0.5)
                if root_1.is_integer() or root_2.is_integer():
                    return (10**n*left+right) %1337
__________________________________________________________________________________________________
