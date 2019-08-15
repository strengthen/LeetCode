__________________________________________________________________________________________________
sample 40 ms submission
class Solution:
    def computeArea(self, A: int, B: int, C: int, D: int, E: int, F: int, G: int, H: int) -> int:
        area = (C-A)*(D-B) + (G-E)*(H-F)
        
        Ai = Bi = Ci = Di = float('inf')
        if A <= E <= C: 
            Ai, Ci = E, min(C, G)
        elif E <= A <= G:
            Ai, Ci = A, min(C, G)
        
        if B <= F <= D: 
            Bi, Di = F, min(D, H)
        elif F <= B <= H:
            Bi, Di = B, min(D, H)
        
        # print(area, Ai, Bi, Ci, Di)
        if Ai != float('inf') and Bi != float('inf'):
            return area-(Ci-Ai)*(Di-Bi)
        
        return area
__________________________________________________________________________________________________
sample 13000 kb submission
class Solution:
    def computeArea(self, A: int, B: int, C: int, D: int, E: int, F: int, G: int, H: int) -> int:
        
        area1 = (D-B)*(C-A)
        area2 = (H-F)*(G-E)
        area_both = area1+area2
        
        # now for intersection
        top = min(D,H)
        bottom = max(B,F)
        left = max(A,E)
        right = min(C,G)
        
        height = top-bottom
        width = right - left
    
        if height >0 and width >0:
            intersection_area = height*width 
        else:
            intersection_area = 0
        return area_both - intersection_area
__________________________________________________________________________________________________
