__________________________________________________________________________________________________
sample 20 ms submission
class Solution:
    
    def pathInZigZagTree(self, label: int) -> List[int]:        
        """
        rows array represents minimum element in row (power of 2) and whether row in negative order (right to left order). 
        rows[i][0] - min element in row
        rows[i][1] - 0 if left to right order, 1 if right to left order
        """
        rows = [(1, 0)] 
        while rows[-1][0]*2 <= label:
            rows.append((rows[-1][0]*2, 1 - rows[-1][1]))
            
        power, negOrder = rows.pop()
        
        res = []
        while label > 1:
            res.append(label)
                
            if negOrder:
                # label position adjusted and parent element easy to find with division by 2 
                a, b = power, power*2 -1
                label = (a + (b - label))//2
            else:
                # label position unadjusted, but parent position need to be adjusted after label//2
                a, b = power//2, power - 1
                label = b - (label//2 - a)
                
            power, negOrder = rows.pop()
            
                          
        res.append(1)
                          
        return res[::-1]
__________________________________________________________________________________________________
sample 24 ms submission
class Solution:
    def pathInZigZagTree(self, label: int) -> List[int]:
        ans, level = [], len(bin(label))-2
        
        for lv in range(level, 0, -1):
            ans.append(label)
            start, end = 2**(lv-1), 2**lv
            label = (end - label + start - 1) // 2
            
        return ans[::-1]
__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def pathInZigZagTree(self, label: int) -> List[int]:
        level, total = 0, 1
        while total < label:
            level += 1
            total += 2**level
            
        res = []
        while label >= 1:
            res.append(label)
            label //= 2
            total -= 2**level
            level -= 1
            label = total-2**level+1+(total-label) 
                
        return res[::-1]                