__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int longestOnes(int[] arr, int k) {
        int l = 0;
        int r = 0;
        while(r < arr.length) {
            k -= arr[r++] ^ 1;
            if (k < 0)
                k += arr[l++] ^ 1;
        }
        return r - l;
    }
}
__________________________________________________________________________________________________
sample 40552 kb submission
class Solution {
    public int longestOnes(int[] nums, int K) {
        Queue<Integer> lastFlipped = new LinkedList<>();
        if (K != 0) lastFlipped.add(-1);
        int max = 0;
        int prev = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 1) {
                if (lastFlipped.size() < K) {
                    lastFlipped.add(i);
                } else {
                    max = Math.max(max, i - prev);
                    if (K != 0) {
                        prev = lastFlipped.remove() + 1;
                        lastFlipped.add(i);
                    } else {
                        prev = i + 1;
                    }
                }
            }
            
        }
        
        // max = Math.max(max, 1);
        return Math.max(max, nums.length - prev);
    }
}
__________________________________________________________________________________________________
