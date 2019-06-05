__________________________________________________________________________________________________
sample 85 ms submission
class Solution {

    int[] nums;
    Random rnd;

    public Solution(int[] nums) {
        this.nums = nums;
        this.rnd = new Random();
    }
    
    public int pick(int target) {
        int result = -1;
        int count = 1;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != target)
                continue;
            if (rnd.nextInt(count++) == 0)
                result = i;
        }
        
        return result;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
__________________________________________________________________________________________________
sample 51272 kb submission
class Solution {

   int[] nums;
    Random random;    
    public Solution(int[] nums) {
        this.nums = nums;
        this.random = new Random();
    }    
    public int pick(int target) {
        int result = -1;
        int occurrenceCount = 0;
        for (int i = 0; i < this.nums.length; i++)
        {
            if (this.nums[i] == target)
                occurrenceCount++;
        }
        //we randomly pick an occurence etween 0-occurence-1
        //Return Value : 
        // Returns a random number.
        // between 0 (inclusive) and n (exclusive).
        int randomOccurrenceToPick = this.random.nextInt(occurrenceCount);
        for (int i = 0; i < this.nums.length; i++)
        {
            if (this.nums[i] == target)
            {
                randomOccurrenceToPick--;
                if (randomOccurrenceToPick == -1)
                {
                    result = i;
                    break;
                }
            }
        }
        return result;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
__________________________________________________________________________________________________
