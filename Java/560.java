__________________________________________________________________________________________________
sample 9 ms submission
class Solution {
    public int subarraySum(int[] nums, int k) {
        int res = 0;
        if (nums == null || nums.length == 0) return res;
        int[] sum = new int[nums.length];
        sum[0] = nums[0];
        for (int i = 1; i < nums.length; i++){
          sum[i] = sum[i-1] + nums[i];
        }

        Map<Integer, Integer> map = new HashMap<>(nums.length * 2);
        map.put(0,1);
        for (int i = 0; i < nums.length; i++){
          res += map.getOrDefault(sum[i]-k, 0);
          int count = map.getOrDefault(sum[i], 0);
          map.put(sum[i], ++count);     
        }   

        return res;
    }
}
__________________________________________________________________________________________________
sample 35972 kb submission
class Solution {
    // T: O(N), S(N)
    // [1, -1, 1, 2, -1]
    //  1   0  1. 3.  2
    //  -1 -2  -1 1.  0 (sum-k)
    public int subarraySum(int[] nums, int k) {       
        Map<Integer, int[]> sumToCounter = new HashMap<>();
        sumToCounter.put(0, new int[]{ 1 });
        int sum = 0;
        int result = 0;
        
        for (int n : nums) {
            sum += n;
            
            int[] v = sumToCounter.get(sum-k);
            // System.out.println(sum-k);
            if (v != null) {
                result += v[0];
                // System.out.println("#"+v[0]);
            }
            
            sumToCounter.computeIfAbsent(sum, key -> new int[]{0})[0]++;
        }
        
        return result;
    }
    
    // T: O(N^2), S:(N) but can be O(1)
    public int subarraySum01(int[] nums, int k) {
        int result = 0;
        if (nums.length == 0) { return result; }
        
        int[] sums = new int[nums.length];
        sums[0] = nums[0];
        if (sums[0] == k) { result++; }
        
        for (int i=1; i < nums.length; i++) {
            sums[i] = sums[i-1] + nums[i];
            
            if (sums[i] == k) { result++; }
        }
        
        for (int i=0; i<nums.length; i++) {
            int correction = nums[i];
            for (int j=i+1; j<nums.length; j++) {
                sums[j] -= correction;
                
                if (sums[j] == k) { result++; }
            }
        }
        
        return result;
    }
}
__________________________________________________________________________________________________
