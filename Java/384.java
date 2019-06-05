__________________________________________________________________________________________________
sample 101 ms submission
class Solution {
    int[] original = null;
    int[] shuffle = null;
    Random rand = null;
 
    public Solution(int[] nums) {
        original = nums;
        shuffle = Arrays.copyOf(nums, nums.length);
        rand = new Random();
    }
 
    /** Resets the array to its original configuration and return it. */
    public int[] reset() {
        shuffle = Arrays.copyOf(original, original.length);
        return shuffle;
    }
 
    /** Returns a random shuffling of the array. */
    public int[] shuffle() {
    	for(int i=0; i<shuffle.length; i++){
            int x = rand.nextInt(shuffle.length - i);
            int idx = x+i;
 
            int tmp = shuffle[idx];
            shuffle[idx] = shuffle[i];
            shuffle[i] = tmp;
        }
 
        return shuffle;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */
__________________________________________________________________________________________________
sample 49560 kb submission
import java.util.*;
class Solution {
    Random rand;
    int[] arr;
    int[] original;
    public Solution(int[] nums) {
        this.arr = nums;
        this.original = nums.clone();
        rand = new Random();
    }
    
    /** Resets the array to its original configuration and return it. */
    public int[] reset() {
        return this.original;
    }
    
    /** Returns a random shuffling of the array. */
    public int[] shuffle() {
        //int n = rand.nextInt(this.arr.length - 1);
        for(int i = 0; i < this.arr.length; i++){
            int n = rand.nextInt(this.arr.length - 1);
            int temp = this.arr[i];
            this.arr[i] = this.arr[n];
            this.arr[n] = temp;
        }
        return this.arr;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */
__________________________________________________________________________________________________
