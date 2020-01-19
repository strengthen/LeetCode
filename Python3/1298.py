__________________________________________________________________________________________________
sample 808 ms submission
class Solution:
    def maxCandies(self, status: List[int], candies: List[int], keys: List[List[int]], containedBoxes: List[List[int]], initialBoxes: List[int]) -> int:
        vst = set()
        havekeys = set()
        noaccess = set()
        Q = collections.deque(initialBoxes)
        c=0
        
        while Q:
            box = Q.popleft()
            if (status[box] or box in havekeys) and box not in vst:
                vst.add(box)
                c+=candies[box]
                havekeys.update(keys[box])
                for x in noaccess:
                    if x in havekeys:
                        Q.append(x)
                for x in containedBoxes[box]:
                    if status[x] or x in havekeys:
                        Q.append(x)
                    else:
                        noaccess.add(x)
            elif box not in vst:
                noaccess.add(box)

                        
        return c
__________________________________________________________________________________________________
sample 812 ms submission
class Solution:
    def maxCandies(self, status: List[int], candies: List[int], keys: List[List[int]], containedBoxes: List[List[int]], initialBoxes: List[int]) -> int:
        ans = 0
        
        found_keys = set()
        cur_boxes = initialBoxes
        
        while cur_boxes:
            nex = []
            fail = []
            for b in cur_boxes:
                if status[b] or ( not status[b] and b in found_keys ):
                    ans += candies[b]
                    found_keys.update( keys[b] )
                    nex.extend( containedBoxes[b] )
                else:
                    fail.append( b )
            if len(fail) != len(cur_boxes):
                nex.extend(fail)
            cur_boxes = nex
        
        return ans
__________________________________________________________________________________________________
