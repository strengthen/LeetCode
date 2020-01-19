__________________________________________________________________________________________________
sample 384 ms submission
class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        sums = list(itertools.accumulate(arr, func = operator.xor)) + [0]
        return [sums[i-1]^sums[j] for i, j in queries]
__________________________________________________________________________________________________
sample 388 ms submission
from itertools import accumulate
from operator import xor
from typing import List


class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        prefix_xors = list(accumulate([0] + arr, xor))
        return [prefix_xors[j + 1] ^ prefix_xors[i] for i, j in queries]
__________________________________________________________________________________________________
