__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    // not mine approach
       public int[] maxSlidingWindow(int[] nums, int k) {
        if(nums.length*k == 0) return new int[0];
        if(k ==1) return nums;
        
        int[] res = new int[nums.length - k + 1];
        int max = nums[0];
        for(int i = 0; i < k; i++){
            if(nums[i]>max) max = nums[i];
        }
        res[0] = max;
        int index = 0;
        for(int i = k; i<nums.length; i++){
            index = i-k+1;
            if(nums[i] > res[index - 1]){
                res[index] = nums[i];
            }else if(nums[index-1]!=res[index-1]){
                res[index] = res[index - 1];
            }else{
                max = nums[i];
                for(int j = index; j <i ; j++){
                    if(nums[j]>max) max = nums[j];
                }
                res[index] = max;
            }
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 37852 kb submission
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        if (n == 0) {
            return nums;
        }
        int[] result = new int[n - k + 1];
        LinkedList<Integer> dq = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (!dq.isEmpty() && dq.peek() < i - k + 1) {
                dq.poll();
            }
            while (!dq.isEmpty() && nums[i] >= nums[dq.peekLast()]) {
                dq.pollLast();
            }
            dq.offer(i);
            if (i - k + 1 >= 0) {
                result[i - k + 1] = nums[dq.peek()];
            }
        }
        return result;
    }
}
__________________________________________________________________________________________________
