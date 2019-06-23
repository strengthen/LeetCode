__________________________________________________________________________________________________
# """
# This is MountainArray's API interface.
# You should not implement it, or speculate about its implementation
# """
#class MountainArray:
#    def get(self, index: int) -> int:
#    def length(self) -> int:

class Solution:
    def findInMountainArray(self, target: int, ma: 'MountainArray') -> int:
        self.d, self.ma, L = {}, ma, ma.length()
        
        mxi = self.findmaxindex(0, L-1)
        if self.ma.get(mxi) < target: return -1
        
        # results in the ascending phase
        ans1 = self.query(0,mxi,target)
        # results in the descending phase
        ans2 = self.query(mxi+1,L-1,target, up=False)
        
        ans = min(ans1,ans2)
        return ans if ans != math.inf else -1
        
    def query(self, l, r, t, up=True):        
        # use binary search to find the appropriate index
        while l<r:
            m = (l+r+1)//2
            if t == self.ma.get(m):
                return m
            
            if self.ma.get(m) < t:
                if up: l = m
                else: r = m-1
            else:                
                if not up: l = m
                else: r = m-1
                    
        return l if self.ma.get(l) == t else math.inf
        
    def findmaxindex(self, l, r):
        # use binary search to find the appropriate index
        if l==r: return l
        cur = (l+r+1)//2
        return self.findmaxindex(l, cur-1) if self.ma.get(cur) < self.ma.get(cur-1) else self.findmaxindex(cur, r)

        
__________________________________________________________________________________________________

__________________________________________________________________________________________________
