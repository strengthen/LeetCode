__________________________________________________________________________________________________
2ms
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int N1 = nums1.length;
        int N2 = nums2.length;
        if(N1 < N2) return findMedianSortedArrays(nums2, nums1);
        
        int lo = 0;
        int hi = N2 * 2;
        while(lo <= hi) {
            int mid2 = lo + (hi - lo) / 2;
            int mid1 = N1 + N2 - mid2;
            
            double L1 = (mid1 <= 0) ? Integer.MIN_VALUE: nums1[(mid1 - 1)/2];
            double L2 = (mid2 <= 0) ? Integer.MIN_VALUE: nums2[(mid2 - 1)/2];
            double R1 = (mid1 >= 2 * N1) ? Integer.MAX_VALUE: nums1[(mid1)/2];
            double R2 = (mid2 >= 2 * N2) ? Integer.MAX_VALUE: nums2[(mid2)/2];
            
            if(L1 > R2) lo = mid2 + 1;
            else if(L2 > R1) hi = mid2 - 1;
            else return (Math.min(R1,R2) + Math.max(L1,L2)) / 2;
        }
        return -1;
    }
}
__________________________________________________________________________________________________
3ms
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
       double s;

	int[] mergerArr= new int[nums1.length+nums2.length];
	System.arraycopy(nums1, 0, mergerArr, 0, nums1.length);
	System.arraycopy(nums2, 0, mergerArr, nums1.length, nums2.length);
	Arrays.sort(mergerArr);
	if(mergerArr.length%2!=0) {
		
		s=mergerArr[(mergerArr.length+1)/2-1];
	}else {
		s=(mergerArr[mergerArr.length/2-1]+mergerArr[(mergerArr.length/2)])/2.0;
	}
	return s;
    }
}
__________________________________________________________________________________________________
4ms
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        double median;
        //int medio;
        int[] nums1s = nums1;
        int[] nums2s = nums2;
        Arrays.sort(nums1s);
        Arrays.sort(nums2s);
        int aLen = nums1.length;
        int bLen = nums2.length;
        int[] result = new int[aLen + bLen];

        System.arraycopy(nums1, 0, result, 0, aLen);
        System.arraycopy(nums2, 0, result, aLen, bLen);
        
        Arrays.sort(result);
        
        if (result.length % 2 == 0) {
            median = (double) (result[(result.length / 2) - 1] + result[result.length / 2]) / 2;
        } else {
            //medio = (int) Math.floor((aLen + bLen)/2);
            median = result[(int) Math.floor((aLen + bLen)/2)];
        }
        return median;
    }
}
__________________________________________________________________________________________________
39944 kb 
class Solution {
    public double findMedianSortedArrays(int[] A, int[] B) {
        int m = A.length;
        int n = B.length;
        if (m > n) { // to ensure m<=n
            int[] temp = A; A = B; B = temp;
            int tmp = m; m = n; n = tmp;
        }
        int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
        while (iMin <= iMax) {
            int i = (iMin + iMax) / 2;
            int j = halfLen - i;
            if (i < iMax && B[j-1] > A[i]){
                iMin = i + 1; // i is too small
            }
            else if (i > iMin && A[i-1] > B[j]) {
                iMax = i - 1; // i is too big
            }
            else { // i is perfect
                int maxLeft = 0;
                if (i == 0) { maxLeft = B[j-1]; }
                else if (j == 0) { maxLeft = A[i-1]; }
                else { maxLeft = Math.max(A[i-1], B[j-1]); }
                if ( (m + n) % 2 == 1 ) { return maxLeft; }

                int minRight = 0;
                if (i == m) { minRight = B[j]; }
                else if (j == n) { minRight = A[i]; }
                else { minRight = Math.min(B[j], A[i]); }

                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }
}
__________________________________________________________________________________________________
40360 kb
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
            if(nums1 == null || nums1.length == 0){
                return nums2.length % 2 == 0 ? (nums2[nums2.length / 2 - 1] + nums2[nums2.length / 2 ]) / 2d : nums2[nums2.length / 2];
            }
            else if(nums2 == null || nums2.length == 0){
                return nums1.length % 2 == 0 ? (nums1[nums1.length / 2 - 1] + nums1[nums1.length / 2 ]) / 2d : nums1[nums1.length / 2];
            }
            else{
                if(nums1.length > nums2.length){
                    int[] tmp = nums2;
                    nums2 = nums1;
                    nums1 = tmp;
                }

                int start = 0, end = nums1.length;
                int cut1 = (start + end + 1) / 2;
                int cut2 = (nums1.length + nums2.length + 1) / 2 - cut1;
                while(true){
                    if((cut1 == 0 || cut2 == nums2.length || nums1[cut1-1] <= nums2[cut2]) && (cut2 == 0 || cut1 == nums1.length || nums2[cut2 - 1] <= nums1[cut1]))
                    {
                        break;
                    }

                    if(cut2 != nums2.length && nums1[cut1 - 1] > nums2[cut2]){
                        end = cut1 - 1;
                        cut1 = (start + end + 1) / 2;
                        cut2 = (nums1.length + nums2.length + 1) / 2 - cut1;
                    }
                    else if(cut2 != nums2.length && nums2[cut2 - 1] > nums1[cut1]){
                        start = cut1;
                        cut1 = (start + end + 1) / 2;
                        cut2 = (nums1.length + nums2.length + 1) / 2 - cut1;
                    }
                }
                System.out.format("cut1: %1$s, cut2: %2$s%n", cut1, cut2);
                
                boolean isEven = (nums1.length + nums2.length) % 2 == 0;
                System.out.format("even:%s", isEven);
                int maxLeft = 0; int minRight = 0;
                                
                maxLeft = cut1 == 0 ? nums2[cut2-1] : cut2 == 0 ? nums1[cut1-1] : Math.max(nums1[cut1-1], nums2[cut2 - 1]);
                minRight = cut1 == nums1.length ? nums2[cut2] : cut2 == nums2.length ? nums1[cut1] : Math.min(nums1[cut1], nums2[cut2]);

                if(isEven){
                    return (maxLeft + minRight) / 2d;
                }
                else{
                    return maxLeft;
                }
            }
        }
}
__________________________________________________________________________________________________
