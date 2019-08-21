__________________________________________________________________________________________________
sample 176 ms submission
class Solution:
    def longestMountain(self, A: List[int]) -> int:
        if len(A) <= 2:
            return 0
        
        is_asc = True
        has_asc = False
        has_desc = False
        prev = A[0]
        max_len = 0
        length = 0
        
        for cur in A[1:]:
            # "Downhill"
            if prev > cur:
                # Reached the peak, going down
                if is_asc and has_asc:
                    has_desc = True
                    is_asc = False
                    has_asc = False
                    length += 1

                    # Rolling down the mountain
                if not is_asc:
                    length += 1
            
            # "Uphill"
            if cur > prev:
                # First step in mountain
                if is_asc:
                    has_asc = True
                    length += 1
                # previously downhill, encountered another uphill
                else:
                    max_len = max(length, max_len)
                    length = 1
                    is_asc = True
                    has_asc = True
            
            if cur == prev:
                if not is_asc:
                    max_len = max(length, max_len)
                length = 0
                is_asc = True
                has_asc = False
                
            prev = cur
        
        if not has_desc:
            return 0
        
        return max(max_len, length)
__________________________________________________________________________________________________
sample 180 ms submission
class Solution:
    def longestMountain(self, A: List[int]) -> int:
        if len(A) < 3:
            return 0
        
        ans = 0
        length = 1
        temp = A[0]
        climbUp = temp < A[1]
        print(temp, A[1], climbUp, length)
        for x in A[1:]:
            if climbUp:
                length += 1
                if not x > temp:
                    climbUp = False
                    if x == temp:
                        length = 1
            elif length == 1:
                if x > temp:
                    climbUp = True
                    length += 1
            else:
                if x < temp:
                    length += 1
                else:
                    ans = max(length, ans)
                    length = 1
                    if x > temp:
                        climbUp = True
                        length += 1
            
            # print(temp, x, climbUp, length)
            temp = x
        
        if length > ans and not climbUp:
            ans = length
                    
        return ans if ans > 2 else 0
__________________________________________________________________________________________________
