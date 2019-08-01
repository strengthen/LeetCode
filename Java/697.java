__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public int findShortestSubArray(int[] nums) {
        if (nums.length == 1) return 1;
        int[] indexs = new int[50000];
        int[] degree = new int[50000];
        for (int i = 0; i < 50000; i++) {
            indexs[i] = -1;
        }
        int max = 1, len = 1;
        for (int i = 0; i < nums.length; i++) {
            if (indexs[nums[i]] == -1) {
                indexs[nums[i]] = i;
            }
            degree[nums[i]]++;
            if (degree[nums[i]] > max) {
                max = degree[nums[i]];
                len = i - indexs[nums[i]] + 1;
            } else if (degree[nums[i]] == max && len > i - indexs[nums[i]] + 1) {
                len = i - indexs[nums[i]] + 1;
            }
        }
        return len;
    }
}
__________________________________________________________________________________________________
sample 40104 kb submission
class Solution {
    public int findShortestSubArray(int[] nums) {
        if(nums == null || nums.length == 0) {
            return 0;
        }
        Map<Integer, int[]> map = new HashMap<>();
        for(int i=0; i<nums.length; i++) {
            if(!map.containsKey(nums[i])) {
                map.put(nums[i], new int[]{1, i, i});
            } else {
                int[] temp = map.get(nums[i]);
                temp[0]++;
                temp[2] = i;
            }
        }
        
        int degree = Integer.MIN_VALUE;
        int result = Integer.MAX_VALUE;
        
        for(int[] value : map.values()) {
            if(value[0] > degree) {
                degree = value[0];
                result = value[2] - value[1] + 1;
            } else if(value[0] == degree) {
                result = Math.min(result, value[2] - value[1] + 1);
            }
        }
        return result;
    }
}
__________________________________________________________________________________________________
