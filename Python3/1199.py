__________________________________________________________________________________________________
class Solution(object):
    def minBuildTime(self, blocks, split):
        N = len(blocks)
        blocks.sort(reverse = True)
        times = [0]
        while len(times) < N:
            times.sort()
            # find weakest candidate
            i = min(xrange(len(times)), key = lambda t: blocks[t] + times[t])
            
            # split candidate
            times[i] += split
            times.append(times[i])
        
        return max(b + times[i] for i,b in enumerate(blocks))
__________________________________________________________________________________________________

__________________________________________________________________________________________________
