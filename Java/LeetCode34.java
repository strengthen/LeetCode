_________________________________________________________________________________________________
0ms
class Solution {
    public int[] searchRange(int[] nums, int target) {
        if(nums.length == 0) return new int[]{-1, -1};
       
        int start = binarySearch(nums, target, 0, nums.length-1);
        int end = start;
        while(start != -1){
            int tempStart = binarySearch(nums, target, 0, start - 1);
            if(tempStart == -1) break;
            start = tempStart;
        }
        while(end != -1){
            int tempEnd = binarySearch(nums, target, end + 1, nums.length-1);
            if(tempEnd == -1) break;
            end = tempEnd;
        }
        
        return new int[]{start, end};
        
    }
    
    private int binarySearch(int[] nums, int target, int min, int max){
        int start = min;
        int end = max;
        if(start <= end){
            int middle = (start + end) / 2;
            int midValue = nums[middle];
            if(midValue == target) return middle;
            else if(midValue > target){
                return binarySearch(nums, target, start, middle -1);
            }else{
                return binarySearch(nums, target, middle + 1, end);
            }
        }
        return -1;

    }
}
__________________________________________________________________________________________________
1ms
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] res = {-1,-1};
        int flag = 0;
        
        for(int i = 0; i < nums.length; i++) {
        	if(nums[i] == target && flag == 0) {
        		res[0] = i;
        		res[1] = i;
        		flag = 1;
        	}
        	else if(nums[i] == target && flag == 1) {
        		res[1] = i;
        	}
        }      
        return res;
    }
}
__________________________________________________________________________________________________
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] result = new int[2];
        result[0] = -1;
        result[1] = -1;
        if(nums == null || nums.length == 0) {
            return result;
        }
        int left = 0;
        int right = nums.length - 1;
        
        while(left + 1 < right) {
            int mid = left + (right - left)/2;
            if(nums[mid] == target) {
                int moveLeft = mid - 1;
                while(moveLeft >= 0 && nums[moveLeft] == target) {
                    moveLeft--;
                }
                int moveRight = mid + 1;
                while(moveRight < nums.length && nums[moveRight] == target) {
                    moveRight++;
                }
                result[0] = moveLeft + 1;
                result[1] = moveRight - 1;
                
                System.out.println(result[0] + " " + result[1] + " result");
                return result;
            }
            if(nums[mid] > target) {
                right = mid;
            }
            if(nums[mid] < target) {
                left = mid;
            }
        }
        System.out.println(left + " " + right);
        if(nums[left] == target && nums[right] == target) {
            result[0] = left;
            result[1] = right;
            return result;
        }
        
        if(nums[left] == target) {
            result[0] = left;
            result[1] = left;
        }
        if(nums[right] == target) {
            result[0] = right;
            result[1] = right;
        }
        
        return result;
    }
}
__________________________________________________________________________________________________
38140 kb
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] result = {-1,-1};
        if (nums == null || nums.length == 0) return result;

        int left=0,right = nums.length-1;
        while(left+1<right) {
            int mid=left+(right-left)/2;
            if(nums[mid] < target) {
                left = mid; 
            } else {
                right = mid;
            }

        }

        System.out.println(""+ left + " " +right);

        if (nums[left] == target) {
            result[0] = left;
            if (nums[right] == target) {
                result[1] = right;
            } else {
                result[1] = left;
            }
            while (right < nums.length-1 && nums[++right] == target) result[1] = right;
            

        } else if (nums[right] == target) {
            result[0] = right;
            result[1] = right;
            while (right < nums.length-1 && nums[++right] == target) result[1] = right;
            
        }
        
        return result;
    }
}
__________________________________________________________________________________________________
38292 kb
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int p1 = 0, p2 = nums.length -1;
        int[] result = {-1,-1};
        while(p1 <= p2){
            if(nums[p1] == target && nums[p2] == target){
                result[0] = p1;
                result[1] = p2;
                return result;
            }
            
            if(nums[p2] > target)
                p2--;
            if(nums[p1] < target)
                p1++;
        }
        return result;
    }
}
__________________________________________________________________________________________________
