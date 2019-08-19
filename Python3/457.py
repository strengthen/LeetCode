__________________________________________________________________________________________________
sample 28 ms submission
class Solution(object):
    def circularArrayLoop(self, nums):
        if not nums or len(nums) < 2:
            return False
        for i, num in enumerate(nums):
            # use a distinct marker for each starting point
            mark = str(i)

            # explore while node is new, direction is same, and is not self loop
            # note: if node has been marked by a different marker, no need to proceed. This gives O(n) time.
            while (type(nums[i]) == int) and (num * nums[i] > 0) and (nums[i] % len(nums) != 0):
                jump = nums[i]
                nums[i] = mark
                i = (i + jump) % len(nums)

            # if self loop, nums[i] is never marked
            # if nums[i] is marked, a cycle is found
            if nums[i] == mark:
                return True

        return False
__________________________________________________________________________________________________
sample 32 ms submission
class Solution(object):
    def circularArrayLoop(self, nums):
        for i, num in enumerate(nums):
            #this num has already been marked as a str because it was part of the route that start with an index<i earlier. 
            #since it come till here means it was not part of a circle, otherwise, it would have already return True during that index search. 
            # so we do not need to start search from this i again because the next location only depend on the current location, the current location can only jump to one place.
            if type(num)== str:
                continue
            # if num is positive pos = True, if num is negative or 0, pos=False
            pos = num>0                
            group = str(i)
            #nums[i] has not been visited during all the previous search, include start from different index,
            #postive sign does not change,
            #the next location is not the current location
            while type(nums[i]) != str and pos == (nums[i] > 0) and nums[i] % len(nums) != 0:
                nxt=(i+nums[i])%len(nums)
                nums[i]= group
                i=nxt
                
                #nxt, nums[i]= nums[i], group
                #i = (i + nxt) % len(nums)
            if nums[i] == group: 
                return True
        return False 
__________________________________________________________________________________________________
