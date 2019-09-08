__________________________________________________________________________________________________
class Solution:
    def maximumNumberOfOnes(self, width: int, height: int, side: int, maxOnes: int) -> int:        # Soltuion: Fold Matrix
            # Take 7*5, side=3, maxOnes=3 as example:
                # . . .|. . .|.                 1 1 .|1 1 .|1
                # . . .|. . .|. fold  6 4 4     1 . .|1 . .|1   
                # . . .|. . .|. ----\ 6 4 4 ==> . . .|. . .|. 
                # ------------- ----/ 3 2 2     -------------   
                # . . .|. . .|.         ||      1 1 .|1 1 .|1 
                # . . .|. . .|.         \/      1 . .|1 . .|1 
                #                  6+6+4 = 16
        
        # Matrix Horizonalize [:] -> [..]
        if width<height:
            width, height = height, width
        
        # Fold
        x,x0 = divmod(width,side)
        v,v0 = divmod(height,side)
        kount = [   x0*v0       , (side-x0)*v0,
                    x0*(side-v0), (side-x0)*(side-v0)
                ]
        
        value = [   (x+1)*(v+1) , x*(v+1)   ,
                    (x+1)*v     , x*v       ,
                ]
        
        # Sum the largest ones
        ans = 0
        for k,n in zip(kount, value):
            if maxOnes > k:
                ans += k*n
                maxOnes -= k
            else:
                return ans + maxOnes *n
        return ans
__________________________________________________________________________________________________

__________________________________________________________________________________________________
