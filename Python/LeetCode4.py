__________________________________________________________________________________________________
56ms
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        new_nums = nums1 + nums2
        new_nums.sort()
        length = len(new_nums)
        if length % 2 == 0:
            return (new_nums[length//2 - 1] + new_nums[length//2]) / 2
        else:
            return new_nums[length // 2]
__________________________________________________________________________________________________
60ms
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:

        A, B = nums1, nums2
        m, n = len(A), len(B)
        if m > n:
            A, B, m, n = B, A, n, m
        if n == 0:
            raise ValueError

        imin, imax, half_len = 0, m, (m + n + 1) // 2
        while imin <= imax:
            i = (imin + imax) // 2
            j = half_len - i
            if i < m and B[j-1] > A[i]:
                # i is too small, must increase it
                imin = i + 1
            elif i > 0 and A[i-1] > B[j]:
                # i is too big, must decrease it
                imax = i - 1
            else:
                # i is perfect
                if i == 0: max_of_left = B[j-1]
                elif j == 0: max_of_left = A[i-1]
                else: max_of_left = max(A[i-1], B[j-1])

                if (m + n) % 2 == 1:
                    return float(max_of_left)

                if i == m: min_of_right = B[j]
                elif j == n: min_of_right = A[i]
                else: min_of_right = min(A[i], B[j])
                return float((max_of_left + min_of_right) / 2)
__________________________________________________________________________________________________
64ms
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        i, n1, n2 = 0, 0, 0
        total_len = len(nums1) + len(nums2)
        merged_arr = []
                
        while i <= total_len / 2:
            if n2 >= len(nums2):
                merged_arr.append(nums1[n1])
                n1 = n1 + 1                
            elif n1 >= len(nums1):
                merged_arr.append(nums2[n2])
                n2 = n2 + 1                
            elif nums1[n1] < nums2[n2]:
                merged_arr.append(nums1[n1])
                n1 = n1 + 1
            else:
                merged_arr.append(nums2[n2])
                n2 = n2 + 1
                
            i = i + 1
                
        return (merged_arr[(total_len - 1) // 2] + merged_arr[total_len // 2] ) / 2
__________________________________________________________________________________________________
12376 kb
class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        if not nums1 or not nums2:
            nums = nums1 or nums2
            if not nums: return ValueError
            mid = len(nums)//2
            odd = len(nums)%2 == 1
            return nums[mid] if odd else (nums[mid] + nums[mid-1])/2

        # choose the smaller array for binary search
        m, n = len(nums1), len(nums2)
        m, n, nums1, nums2 = (m, n, nums1, nums2) if m<=n else (n, m, nums2, nums1)

        l, r = 0, m
        total = (n+m+1)//2		# '+1' for odd cases, to have left side 1 larger than right side 
        while l <= r:
            i = l + (r-l)//2    # how many of nums1 we choose      
            j = total - i    # how many of nums 2 we need
            
            if i < m and nums2[j-1] > nums1[i]:
                l = i+1
            elif i > 0 and nums1[i-1] > nums2[j]:
                r = i-1
            else:    # ready to return 
                max_left = max(nums1[i-1], nums2[j-1]) if (i>0 and j>0) else (nums1[i-1] if i>0 else nums2[j-1])
                if (m+n)%2 == 1:	# odd number of items
                    return max_left

                min_right = min(nums1[i], nums2[j]) if (i<m and j<n) else (nums1[i] if i<m else nums2[j])
                return (max_left + min_right)/2
__________________________________________________________________________________________________
12404 kb 
class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        leftMax, rightMin = 0, 0
        m, n = len(nums1), len(nums2)
        if m > n:
            nums1, nums2, m, n = nums2, nums1, n, m
        mini, maxi, split = 0, m, (m+n+1) // 2
        while mini <= maxi:
            i = (mini + maxi) // 2
            j = split - i
            # print(i, j)
            if i < m and nums2[j-1] > nums1[i]:
                mini += 1
            elif i > 0 and nums1[i-1] > nums2[j]:
                maxi -= 1
            else:
                if i == 0:
                    leftMax = nums2[j-1]
                elif j == 0: 
                    leftMax = nums1[i-1]
                else: 
                    leftMax = max(nums1[i-1], nums2[j-1])
                
                if (m + n) % 2 == 1:
                    return leftMax
                
                if i == m:
                    rightMin = nums2[j]
                elif j == n: 
                    rightMin = nums1[i]
                else: 
                    rightMin = min(nums1[i], nums2[j])
                
                return (leftMax + rightMin) / 2.0
__________________________________________________________________________________________________
