__________________________________________________________________________________________________
class Solution:
	# Time O(nlogn), Space O(n)
    def rearrangeBarcodes(self, barcodes: List[int]) -> List[int]:
        N = len(barcodes)
        counter = collections.Counter(barcodes)
        barcodes = sorted(barcodes, key=lambda n:(-counter[n], n))
        half = (N + 1) // 2
        barcodes[0:N:2], barcodes[1:N:2] = barcodes[0:half], barcodes[half:]
        return barcodes
__________________________________________________________________________________________________

__________________________________________________________________________________________________
