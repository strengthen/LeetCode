__________________________________________________________________________________________________
0ms
class Solution {
    public int search(int[] A, int target) {
        int lo = 0;
        int hi = A.length-1;
        if(A == null || A.length<1) return -1;
        while(lo < hi){
            int mid = ( lo + hi) / 2;
            if(A[mid] == target) return mid;
            if(A[lo]<= A[mid]){
                if(A[lo] <= target && target < A[mid]){
                    hi = mid - 1;
                }else{
                    lo = mid+1;
                }
            }else{
                if( target >A[mid] && A[hi] >= target){
                    lo = mid +1;
                    
                }else{
                    hi = mid - 1;
                }
                
            }
        }
        
        return A[lo] == target ? lo : -1;
    }
}
__________________________________________________________________________________________________
0ms
class Solution {
    public int search(int[] nums, int target) {
         if (nums == null || nums.length == 0) {
             return -1;
         }
 
         int l = 0, r = nums.length - 1;
         while (l <= r) {
             int m = (l + r) / 2;
             if (nums[m] == target) {
                 return m;
             }
             if (nums[m] >= nums[l]) {
                 if (nums[l] <= target && target < nums[m]) {
                     r = m - 1;
                 } else {
                     l = m + 1;
                 }
             } else {
                 if (nums[m] < target && target <= nums[r]) {
                     l = m + 1;
                 } else {
                     r = m - 1;
                 }
             }
         }
         return -1;
     }
 }
__________________________________________________________________________________________________
2ms
class Solution {
    public int search(int[] nums, int target) {
        if (nums.length == 0 ) return -1;
        int l = 0, r = nums.length - 1;
        while (l < r) {
            int mid = (r -l + 1)%2 == 0 ? (l + r) / 2 +1 : (l+r)/2;
            if (nums[mid] > nums[l]) l = mid ;
            else r = mid - 1;
        }
        
        int rot = l ;
        System.out.println(rot);
        int res = search(nums, rot + 1, nums.length -1, target);
        res = res == -1 ? search(nums, 0, rot, target) : res;
        
        return res;
        
    }
    
    private static int search(int[] nums, int l, int r, int target) {
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (target < nums[mid]) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }
}
__________________________________________________________________________________________________
35368 kb
class Solution {
    public int search(int[] nums, int target) {
        // [4,5,6,7,8,9,0]
        /*
         *  1. Do binary search to find pivot
         *  2. Do "shifted" binary search to find target
         */
        if (nums.length == 0) {
            return -1;
        }
        int pivotIndex = findPivot(nums, 0, nums.length - 1);
        System.out.println("pivot index: " + pivotIndex);
        return findTarget(nums, pivotIndex, 0, nums.length - 1, target);
    }

    private static int findPivot(int[] nums, int from, int to) {
        System.out.println("from " + from + " to " + to + " len " + nums.length);

        int index = (from + to) / 2;
        System.out.println("test " + nums[index] + " from " + nums[from] + " to " + nums[to]);
        if (nums[index] < nums[from]) {
            int nextTo = index - 1;
            if (nums[index] < nums[nextTo]) {
                return index;
            }
            return findPivot(nums, from, nextTo);
        }
        if (nums[index] > nums[to]) {
            int nextFrom = index + 1;
            if (nums[index] > nums[nextFrom]) {
                return nextFrom;
            }
            return findPivot(nums, nextFrom, to);
        }

        return from;
    }

    private static int toShifted(int i, int pivot, int len) {
        int shifted = i + pivot;
        return shifted < len ? shifted : shifted - len;
    }
    
    private static int fromShifted(int i, int pivot, int len) {
        int unshifted = i - pivot;
        return unshifted >= 0 ? unshifted : unshifted + len;
    }
    
    private static int findTarget(int[] nums, int pivot, int from, int to, int target) {
        int index = (from + to) / 2;
        int shiftedIndex = toShifted(index, pivot, nums.length);
        //System.out.println("from " + from + " to " + to + " len " + nums.length + " idx " + index + " shifted idx " + shiftedIndex + " num " + nums[shiftedIndex]);
        if (nums[shiftedIndex] == target) {
            return shiftedIndex;
        }
        
        if (from >= to) {
            //System.out.println("return -1 from <= to");
            return -1;
        }
        
        if (target < nums[shiftedIndex]) {
            if (index == 0) {
                //System.out.println("return -1 index == 0");
                return -1;
            }
            int nextTo = fromShifted(shiftedIndex - 1, pivot, nums.length);
            return findTarget(nums, pivot, from, nextTo, target);
        }

        if (target > nums[shiftedIndex]) {
            if (index == nums.length - 1) {
                //System.out.println("return -1 index == nums.length - 1");
                return -1;
            }
            int nextFrom = fromShifted(shiftedIndex + 1, pivot, nums.length);
            return findTarget(nums, pivot, nextFrom, to, target);
        }
        
        assert false;
        return 0;
    }
}
__________________________________________________________________________________________________
35456 kb
class Solution {
    public int search(int[] nums, int target) {
        if (nums == null || nums.length == 0) return -1;
        return rec(nums, target, 0, nums.length-1);
    }
    
    private int rec(int[] N, int t, int l, int r) {
        if (l > r) return -1;
        int m = l + (r-l)/2;
        
        if (N[m] == t) return m;
        if (N[0] <= N[m]) {
            if (N[0] <= t && t < N[m]) return rec(N, t, l, m-1);
            else return rec(N, t, m+1, r);
        } else {
            if (N[m] < t && t <= N[r]) return rec(N, t, m+1, r);
            else return rec(N, t, l, m-1);
        }
    }
}
__________________________________________________________________________________________________