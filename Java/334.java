__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
  public boolean increasingTriplet(int[] a) {
    if (a.length < 3) {
        return false;
    }

    int small = Integer.MAX_VALUE; // smallest ending integer of subsequence with length 1
    int large = Integer.MAX_VALUE;  // smallest ending integer of ascending subsequence with length 2
      
    for (int num : a) {
        if (num < small) {
            small = num;
        } else if (num > small && num < large) {
            large = num;
        } else if (num > large) {
            // when num > large, we are sure that there exists a number that is before "large" and smaller than "large"
            return true;            
        }
    }
      
      return false;
  }
}
__________________________________________________________________________________________________
sample 36492 kb submission
public class Solution {

  public boolean increasingTriplet(int[] nums) {
    if (nums == null || nums.length < 3) {
      return false;
    }

    int[] cache = new int[2];
    cache[0] = cache[1] = Integer.MAX_VALUE;
    for (int i = 0; i < nums.length; i++) {
      if (nums[i] > cache[1]) {
        return true;
      } else if (nums[i] > cache[0] && nums[i] <= cache[1]) {
        cache[1] = nums[i];
      } else {
        cache[0] = nums[i];
      }
    }
    return false;
  }
}
__________________________________________________________________________________________________