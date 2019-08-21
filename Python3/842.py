__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def splitIntoFibonacci(self, S: str) -> List[int]:
        for i in range(min(10,len(S))):
            x=S[:i+1]
            if x!= '0' and x.startswith('0'):
                break
            a=int(x)
            for j in range(i+1,min(i+10,len(S))):
                y=S[i+1:j+1]
                if y != '0' and y.startswith('0'):
                    break
                b=int(y)
                fib=[a,b]
                k=j+1
                while k<len(S):
                    nxt=fib[-1]+fib[-2]
                    nxtS=str(nxt)
                    if nxt <= 2 **31 -1 and S[k:].startswith(nxtS):
                        fib.append(nxt)
                        k+=len(nxtS)
                    else:
                        break
                else:
                    if len(fib) >=3:
                        return fib
        return []
__________________________________________________________________________________________________
sample 13156 kb submission
class Solution:
    def splitIntoFibonacci(self, S: str) -> List[int]:
        """
        We choose the starting two numbers (n^2), then iteratively continue the
        pattern (n).
        Time: O(n^3)
        """
        def _fib_seq(num1, num2, remainder):
            fib = [num1, num2]
            while remainder:
                sums = num1 + num2
                cut = len(str(sums))
                num3, remainder = int(remainder[:cut]), remainder[cut:]
                if sums != num3 or sums >= 2**31:
                    return []
                fib.append(num3)
                num1, num2 = num2, num3
            return fib
        for i in range(2, len(S) - 1):
            nums, remainder = S[:i], S[i:]
            for cut in range(1, len(nums)):
                num1, num2 = nums[:cut], nums[cut:]
                if (len(num1) > 1 and num1.startswith('0')) or \
                        (len(num2) > 1 and num2.startswith('0')):
                    continue
                num1, num2 = int(num1), int(num2)
                fib = _fib_seq(num1, num2, remainder)
                if fib:
                    return fib
        return []
__________________________________________________________________________________________________
