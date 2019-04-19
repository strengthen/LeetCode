__________________________________________________________________________________________________
0ms
public class Solution {
    public int removeElement(int[] nums, int val) {
       int end=nums.length;
    int k=0;
    for (int i = 0; i < end; i++) {
        if (nums[i]==val) {
            for (int j = i; j < end-1; j++) {
                k=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=k;
            }
            end--;
            i--;
        }
    }
    return end;
    }
}
__________________________________________________________________________________________________
0ms
class Solution {
    public int removeElement(int[] nums, int val) {
        int total = nums.length;
        for (int i = 0; i < total ; i++) {
            if (val == nums[i]) {
                if ( i < total - 1) {
                    nums = removeOneElement (nums, i, total);
                    i = i - 1;
                }
                --total;
            }
        }
        return total;
    }
    
    private int[] removeOneElement (int[] array, int pos, int length) {
        for (int i = pos; i < length - 1; i++ ) {
            array[i] = array[i+1];
        }
        return array;
    }
}
__________________________________________________________________________________________________
1ms
class Solution {
    public int removeElement(int[] nums, int val) {
        Arrays.sort(nums);
        int j = nums.length-1;
        for(int i = 0 ; i < nums.length ; i++){
            if(nums[i] == val){
                nums[i] =nums[j];
                j--;
            }
        }
        return j+1;
    }
}
__________________________________________________________________________________________________
34840 kb 
class Solution {
    public int removeElement(int[] nums, int val) {
        int i = 0;
        for (int j = 0; j < nums.length; j++) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
}
__________________________________________________________________________________________________
34880 kb
class Solution {
    public int removeElement(int[] nums, int val) {
        int slow = 0, fast = 0;
        while (fast < nums.length) {
            if (nums[fast] != val) {
                nums[slow++] = nums[fast];
            }
            fast++;
        }
        return slow;
    }
}
__________________________________________________________________________________________________
