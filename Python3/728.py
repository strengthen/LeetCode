__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def selfDividingNumbers(self, left, right):
        nums = []
        for n in range(left, right+1):
            if 1<=n<10:
                nums.append(n)
            else:
                is_divide = True
                nn = n
                while n > 0:
                    if n%10 == 0 or nn % (n%10) != 0:
                        is_divide = False
                        break
                    n //= 10
                if is_divide:
                    nums.append(nn)
        return nums
__________________________________________________________________________________________________
sample 12944 kb submission
class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        ans = []
        for i in range(left, right + 1):
            shift = i
            is_self_dividing = True
            while(shift != 0):
                ones_digit = shift % 10
                if ones_digit == 0 or i % ones_digit != 0:
                    is_self_dividing = False
                    break
                shift = (shift - ones_digit) // 10
            if is_self_dividing:
                ans.append(i)
        return ans
__________________________________________________________________________________________________
