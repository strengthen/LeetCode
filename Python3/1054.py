__________________________________________________________________________________________________
sample 264 ms submission

class Solution:
    def rearrangeBarcodes(self, barcodes: List[int]) -> List[int]:
        n = len(barcodes)
        idxes = collections.deque(list(range(0, n, 2)) + list(range(1, n, 2)))
        counter = collections.Counter(barcodes)
        top_1, freq, counter = self.top(counter)
        ans = [None] * n
        for _ in range(freq):
            ans[idxes.popleft()] = top_1
        for num, cnt in counter.items():
            for _ in range(cnt):
                ans[idxes.popleft()] = num
        return ans
    
    def top(self, counter):
        most = 0
        res = None 
        for key, val in counter.items():
            if val > most:
                most = val 
                res = key
        del counter[res]
        return res, most, counter 
__________________________________________________________________________________________________
sample 276 ms submission
class Solution:
    def rearrangeBarcodes(self, barcodes: List[int]) -> List[int]:
        from itertools import chain, zip_longest
        from collections import Counter 
        from itertools import repeat, chain 
        
        if len(barcodes) == 1:
            return barcodes
        
        # result =  sorted(barcodes,key=barcodes.count,reverse = True)
        result = list(chain.from_iterable(repeat(i, c) 
                    for i, c in Counter(barcodes).most_common())) 
        # print(result)
        n = len(barcodes)//2
        if len(barcodes)%2 != 0:
            firstHalf = result[:n+1]
            secondHalf = result[n+1:]
        else:
            firstHalf = result[:n]
            secondHalf = result[n:]

            
        
        # print(firstHalf)
        # print(secondHalf)
        c = list(chain.from_iterable(zip_longest(firstHalf, secondHalf)))
        output = [ x for x in c if x is not None ]
        
        return output
__________________________________________________________________________________________________
sample 280 ms submission
from collections import Counter
class Solution:
    def rearrangeBarcodes(self, barcodes: List[int]) -> List[int]:
        c = Counter(barcodes)
        new = [0] * len(barcodes)
        n = len(barcodes)
        i = 0
        for barcode, frequency in c.most_common():
            for _ in range(frequency):
                new[i] = barcode
                i += 2
                if i >= n:
                    i = 1
        return new        