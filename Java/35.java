__________________________________________________________________________________________________
0ms
class Solution {
    public int searchInsert(int[] nums, int target) {
        int l = 0, r = nums.length - 1;
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            
            if(nums[mid] == target)
                return mid;
            
            if(nums[mid] < target)
                l = mid + 1;
            else r = mid - 1;
        }
        
        return l;
    }
}
__________________________________________________________________________________________________
0ms
class Solution {
    public int searchInsert(int[] nums, int target) {
         if (nums == null || nums.length == 0) {
             return 0;
         }
         for (int i = 0; i < nums.length; i++) {
             if (nums[i] == target) {
                 return i;
             } else if (nums[i] < target) {
                 if ((i + 1 < nums.length && nums[i + 1] > target)
                         || (i + 1 == nums.length)) {
                     return i + 1;
                 }
             }
         }
         return 0;
     }
 }
__________________________________________________________________________________________________
2ms
class Solution {
    public int searchInsert(int[] nums, int target) {
        ArrayList<Integer> list = new ArrayList<>();
        for(int num: nums) list.add(num);
        if(list.contains(target)) return list.indexOf(target);
        else{
            for(int i=0; i<list.size(); i++){
                if(list.get(i)>target){
                    return i;
                }
            }
        }
        return list.size();
    }
}
__________________________________________________________________________________________________
34960 kb
class Solution {
    public int searchInsert(int[] nums, int target) {
        if(nums.length == 0 || nums[0] == target) return 0;
        if(nums[nums.length-1] == target) return nums.length-1;
        return binarySearch(nums, 0, nums.length-1, target);
    }
    
    private int binarySearch(int[] nums, int start, int end, int target) {
        
        
        if(end < start) return start;
        //if(end==start) return (nums[start] >= target ? start : start+1);
        
        int mid = (end-start)/2 + start;
        if(nums[mid]==target) {
            return mid;
        } 
        if(start < mid && nums[mid]>target && nums[mid-1]<=target) {
            return nums[mid-1] == target ? mid-1 : mid;
        }
        if(mid < end && nums[mid]<target && nums[mid+1]>=target) {
            return mid+1;
        }
        if(nums[mid]>target){
            return binarySearch(nums, start, mid-1, target);
        } else {
            return binarySearch(nums, mid+1, end, target);
        }
    }
}
__________________________________________________________________________________________________
35340 kb
class Solution {
    public int searchInsert(int[] nums, int target) {
        if(nums == null) throw new IllegalArgumentException("Invalid input");
        if(nums.length == 0) return 0;
        int left = 0;
        int right = nums.length - 1;
        while(left + 1 < right){ //right, left
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] < target) left = mid;
            if(nums[mid] > target) right = mid;
        }
        //post-processing
        if(nums[left] == target) return left;
        if(nums[right] == target) return right;
        if(nums[left] > target) return left;
        if(nums[right] > target) return right;
        return /* java.lang.Math.abs(nums[left] - target) < java.lang.Math.abs(nums[right] - target) ? left + 1 :  */right + 1;

    }
}
__________________________________________________________________________________________________