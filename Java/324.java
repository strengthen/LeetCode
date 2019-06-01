__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public void wiggleSort(final int[] nums) {
        int[] val = Arrays.copyOf(nums, nums.length);
        Arrays.sort(val);
        int j=0;
        if(val.length%2==0) {
            for(int i=val.length-2; i>=0; i-=2,j++) nums[i]=val[j];
            for(int i=val.length-1; i>=0; i-=2,j++) nums[i]=val[j];
        } else {
            for(int i=val.length-1; i>=0; i-=2,j++) nums[i]=val[j];
            for(int i=val.length-2; i>=0; i-=2,j++) nums[i]=val[j];
        }
    }
}
__________________________________________________________________________________________________
sample 37728 kb submission
class Solution {
    public void wiggleSort(int[] nums) {
        int m = findKthLargest(nums, (nums.length + 1) / 2, 0, nums.length - 1);
        System.out.println(m);
        int i = 0, j = 0, k = nums.length - 1, n = nums.length;
        while (j <= k) {
            int vj = indexMapping(j, n);
            if (nums[vj] > m) {
                int vi = indexMapping(i, n);
                swap(nums, vi, vj);
                i++;
                j++;
            } else if (nums[vj] < m) {
                int vk = indexMapping(k, n);
                swap(nums, vk, vj);
                k--;
            } else {
                j++;
            }
        }
    }
    
    private int indexMapping(int x, int n) {
        return (2 * x + 1) % (n | 1);
    }
    
    private void swap(int[]nums, int x, int y) {
        System.out.println("x="+x+" y="+y);
        int temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;
    }
    
    private int findKthLargest(int[] nums, int k, int l, int r) {        
        int mid = nums[l], i = l, j = r;
        while (i < j) {
            while (i < r && nums[i] >= mid) i++;
            while (j > l && nums[j] <= mid) j--;
            if (i < j) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
        nums[l] = nums[j];
        nums[j] = mid;
        
        if (j == k - 1) {
            return nums[j];
        } else if (j > k - 1) {
            return findKthLargest(nums, k, l, j - 1);
        } else {
            return findKthLargest(nums, k, j + 1, r);
        }
    }
}
__________________________________________________________________________________________________
