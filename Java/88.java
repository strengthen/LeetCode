__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int f = i + j + 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[f] = nums1[i];
                i--;
            } else {
                nums1[f] = nums2[j];
                j--;
            }
            f--;
        }
        
        for (int k = 0; k < j + 1; k++) {
            nums1[k] = nums2[k];
        }
    }
}
__________________________________________________________________________________________________
sample 34680 kb submission
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int p = m + n - 1;
        m--;
        n--;
        while (m >= 0 && n >= 0) {
            if (nums1[m] > nums2[n]) {
                nums1[p--] = nums1[m--];
            } else {
                nums1[p--] = nums2[n--];
            }
        }
        
        while (n >= 0) {
            nums1[p--] = nums2[n--];
        }
    }
}
__________________________________________________________________________________________________
