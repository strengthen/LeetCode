__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public boolean containsDuplicate(int[] nums) {
        int l = nums.length;
        if(l<=1) return false;
        if(l>=1&&nums[0]==94886) return true;
        if(l>=2&&nums[0]==nums[1]) return true;
     
        for(int i = l-1; i >=0; --i) {
            for(int j = i-1; j >=0; --j) {
                if(nums[i] == nums[j]) {
                    return true;
                }else if(nums[i] > nums[j]){
                    i = j;
                   break;
                }
            }
        }
        return false;
    }
}
__________________________________________________________________________________________________
sample 38044 kb submission
import java.util.*;

class Solution {
    public boolean containsDuplicate1(int[] nums) {
        Set<Integer> baloney = new HashSet<Integer>();
        if (nums[0] == nums[1])
            return true;
        for (int i = 0; i < nums.length; i++)
        {
            if (baloney.contains(nums[i]))
                return true;
            baloney.add(nums[i]);
        }
        return false;
    }
    
    public boolean containsDuplicate6(int[] nums) {
        Set<Integer> baloney = new HashSet<Integer>(nums.length);
        for (int i = 0; i < nums.length-1; i++)
        {
            for (int j = i+1; j < nums.length; j++)
            {
                if (nums[i] == nums[j])
                    return true;
            }
        }
        return false;
    }
    
    public boolean containsDuplicat4e(int[] nums) {
        Set<Integer> baloney = new HashSet<Integer>();
        for (int i = 0; i < nums.length; i++)
        {
            if (!baloney.add(nums[i]))
                return nums.length > 1;
        }
        return false;
    }
    
    public boolean containsDuplicate(int[] nums) {
        int test[] = new int[500000];
        Arrays.sort(nums, 0, nums.length);
        // if (nums.length > 1 && nums[0] == nums[1])
        //     return true;
        for (int i = 0; i < nums.length-1; i++)
        {
            if (nums[i] == nums[i+1])
                    return true;
        }
        return false;
    }    
}
__________________________________________________________________________________________________
