__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def countDigitOne(self, n):

        return self.helper(n)

    def helper(self, n):

        if n <= 0:
            return 0

        if n < 10:
            return 1

        count = 0
        num = n
        while num > 0:
            count += 1
            num = num // 10

        multiplier = 10 ** (count - 1)
        first_num, remainder = divmod(n, multiplier)

        # print('count =', count)
        res = 10 ** (count - 2) * (count - 1)  # 巧妙
        print('res =', res)

        if first_num == 1:
            res += (remainder + 1)
            res += self.helper(remainder)
        else:
            res += 10 ** (count - 1)
            res += (first_num - 1) * 10 ** (count - 2) * (count - 1)
            res += self.helper(remainder)

        return res
__________________________________________________________________________________________________
sample 32 ms submission
class Solution:
    def countDigitOne(self, n: int) -> int:
        m, cnt = 1, 0
        # Buggggg, was "while m < n:"
        while m <= n:
            a, b = n // m, n % m
            # +8 is used to distinguish 0, 1, >=2 cases
            cnt += ((a + 8) // 10) * m + (b + 1 if a % 10 == 1 else 0)
            m *= 10
        return cnt
__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def countDigitOne(self, n: int) -> int:
        numstack = []
        value = n
        while value > 0:
            numstack.append(value%10)
            value = value//10
        total = 0
        front = 0
        nlen = len(numstack)
        while numstack:
            num = numstack.pop()
            nlen -= 1
            if num == 0:
                total += front*pow(10,nlen)
            elif num == 1:
                total += front*pow(10,nlen)+n%pow(10,nlen)+1
            else:
                total += (front+1)*pow(10,nlen)
            front = front*10+num
        return total