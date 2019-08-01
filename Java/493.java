__________________________________________________________________________________________________
sample 32 ms submission
class Solution {
    int count = 0;
    
    public int reversePairs(int[] nums) {
        mergeSort(nums, Arrays.copyOf(nums, nums.length), 0, nums.length - 1);
        return count;
    }
    
    public void mergeSort(int[] nums, int[] buff, int low, int high){
        if(low >= high) return;
        int m = low+ (high-low)/2;
        mergeSort(buff, nums, low, m);
        mergeSort(buff, nums, m + 1, high);
        int left = low, right = m + 1;
        while(left <= m && right <= high){
            if(buff[left] > buff[right] * 2L){
                count += m - left + 1;
                right++;
            }else{
                left++;
            }
        }
        merge(nums, buff, low, high);
    }
    
    private void merge(int[] nums, int[] buff, int low, int high){
        int m = (low + high) / 2;
        int left = low, right = m + 1, i = low;
        while(left <= m && right <= high){
            if(buff[left] < buff[right]){
                nums[i++] = buff[left++];
            }else{
                nums[i++] = buff[right++];
            }
        }
        while(left <= m) nums[i++] = buff[left++];
        while(right <= high) nums[i++] = buff[right++];
    }
}
__________________________________________________________________________________________________
sample 49880 kb submission
/*
 * @lc app=leetcode id=493 lang=java
 *
 * [493] Reverse Pairs
 */
class Solution {
    public int reversePairs(int[] nums) {
        return mergeSortCount(nums, 0, nums.length-1);
    }
    private int mergeSortCount(int[] nums, int low, int high) {
        if (high <= low) return 0;
        int mid = low + (high - low) / 2;
        int count = 0;
        // reverse pairs from the sorted left half
        count += mergeSortCount(nums, low, mid);
        // reverse pairs from the sorted right half
        count += mergeSortCount(nums, mid+1, high);
        // one from the left half one from the right half
        count += mergeCount(nums, low, mid, high);
        return count;
    }
    private int mergeCount(int[] nums, int low, int mid, int high) {
        int count = 0;
        int i=low, j=mid+1;
        while (i<=mid && j<=high) {
            if (nums[i] <= 2L*nums[j]) i++;
            else {
                count += mid-i+1;
                j++;
            }
        }
        int[] sorted = new int[high-low+1];
        int k=0;
        i=low;
        j=mid+1;
        while (i<=mid && j<=high) {
            if (nums[i] <= nums[j]) {
                sorted[k] = nums[i];
                i++;
            } else {
                sorted[k] = nums[j];
                j++;
            }
            k++;
        }
        while (i<=mid) {
            sorted[k] = nums[i];
            k++;
            i++;
        }
        while (j<=high) {
            sorted[k] = nums[j];
            k++;
            j++;
        }
        for (int n=0; n<k; n++) {
            nums[low+n] = sorted[n];
        }
        return count;
    }
}

__________________________________________________________________________________________________
