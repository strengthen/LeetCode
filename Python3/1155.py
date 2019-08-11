__________________________________________________________________________________________________
class Solution:
    def numRollsToTarget(self, d: int, f: int, target: int) -> int:
        mem = {}
        def get_num(*args):
            if args in mem:
                return mem[args]
            n, t = args
            if t < n or t > n * f:
                return 0
            if n == 0:
                return 1 if t == 0 else 0
            
            result = sum(
                get_num(n - 1, t - i) for i in range(1, f + 1)
            ) % 1000000007
            mem[args] = result
            return result
        
        return get_num(d, target)            
__________________________________________________________________________________________________

__________________________________________________________________________________________________
