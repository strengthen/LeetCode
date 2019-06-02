__________________________________________________________________________________________________
sample 37932 kb submission
public class Solution {

	public int fixedPoint(int[] a) {
		int lo = 0;
		int hi = a.length - 1;

		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			if (a[mid] > mid) {
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}

		while (lo > 0 && a[lo - 1] == lo - 1) {
			lo--;
		}

		return a[lo] == lo ? lo : -1;
	}

}
__________________________________________________________________________________________________
sample 37940 kb submission
class Solution {
    public int fixedPoint(int[] A) {
        for (int i = 0; i < A.length; i++) {
            if (A[i] == i) return i;
        }
        return -1;
    }
}
__________________________________________________________________________________________________
sample 37980 kb submission
class Solution {
    public int fixedPoint(int[] nums) {
        int lo = 0, hi = nums.length - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < mid) {
                lo = mid + 1;
            } else if (nums[mid] > mid) {
                hi = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
}