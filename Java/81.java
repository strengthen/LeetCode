__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean search(int[] nums, int target) {
       int l=0; int h=nums.length-1;
		
		while(l<=h) {
			int mid=l+(((h-l)/2)>>1);
			if(nums[mid]==target) return true;
			
			//if right is sorted and left is unsorted 
			else if(nums[mid]<nums[h]||nums[mid]<nums[l]) {
				//means mid ---- high is sorted or low----mid is sorted
				if(nums[mid]<target&&target<=nums[h]) {
					// it means the number is lying on right side
					l=mid+1;
				}else {
					h=mid-1;
				}
			}else if(nums[mid]>nums[h]||nums[mid]>nums[l]) {
				//means mid ---- high is sorted or low----mid is sorted
				if(nums[mid]>target&&nums[l]<=target) {
					// it means the number is lying on right side
					h=mid-1;
				}else {
					l=mid+1;
				}
			}else{
                h--;
            }
		}
		return false;
    }
}
__________________________________________________________________________________________________
sample 34724 kb submission
// does not work for 1,1,3,1 and searching for 3.

class Solution {
    public boolean search(int[] nums, int target) {
        
        return searchH(nums, target, 0, nums.length - 1);
    }
    
    private boolean searchH(int[] nums, int target, int start, int end) {
        
        if(start > end) {
            return false;
        }
        
        int mid = (start + end) / 2;
        
        if(nums[mid] == target) {
            return true;
        }
        else if(nums[mid] < nums[end]) {
            
            //sorted array
            if(target > nums[mid] && target <= nums[end]) {
                return searchH(nums, target, mid + 1, end);
            }
            else {
                return searchH(nums, target, start, mid - 1);
            }
        }
        else if (nums[start] < nums[mid]) {
        
            if(target >= nums[start] && target < nums[mid]) {
                return searchH(nums, target, start, mid-1);
            }
            else {
                return searchH(nums, target, mid + 1, end);
            }
        }
        else {
            if(nums[start] == nums[mid]) {
                return searchH(nums, target, start + 1, end);
            }
            else {
                return searchH(nums, target, start, end - 1);
            }
        }
    }
}
__________________________________________________________________________________________________
