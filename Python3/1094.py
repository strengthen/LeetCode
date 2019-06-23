__________________________________________________________________________________________________
class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        trips=sorted(trips,key=lambda x:x[1])
        carry=[]
        ending_times=[]
        for idx,i in enumerate(trips):
            jdx=0
            while(jdx<len(ending_times)):
                if(ending_times[jdx]<=i[1]):
                    ending_times.pop(jdx)
                    carry.pop(jdx)
                else:
                    jdx+=1
            carry+=[i[0]]
            ending_times+=[i[2]]
            if(sum(carry)>capacity):
                return False

        return True
        
__________________________________________________________________________________________________

__________________________________________________________________________________________________
